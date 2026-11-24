#!/usr/bin/env bash
# Fetch and build the toolchains into tmp/toolchains (no root needed).
#
#  - Red Hat Linux 9 i386 (gcc 3.2.2-5, binutils 2.13.90.0.18-9, glibc
#    2.3.2-27.9.7): the host Sony built psp-gcc on.  Its glibc also runs the
#    i386 compiler binaries outside the sandbox.
#  - the original psp-gcc 1.3.1 and 1.7.1 releases: psp-as, psp-cpp and the
#    reference cc1 binaries.
#  - modern mips-linux-gnu binutils, for splat's assembly and linking.
#
# Then tools/build_gcc.sh builds cc1 from each gcc<version>_src.
# Needs: bwrap, setarch, python3, curl, apt-get (download only), dpkg-deb.
set -euo pipefail
cd "$(dirname "$0")/.."
ROOT=$PWD
T=$ROOT/tmp/toolchains
mkdir -p "$T/bin" "$T/rpms"

M=https://mirror.math.princeton.edu/pub/redhat-archive/redhat/linux
GA=$M/9/en/os/i386/RedHat/RPMS
UPD=$M/updates/9/en/os
cd "$T/rpms"
for p in $GA/binutils-2.13.90.0.18-9.i386.rpm $GA/cpp-3.2.2-5.i386.rpm \
	 $GA/gcc-3.2.2-5.i386.rpm $GA/libgcc-3.2.2-5.i386.rpm \
	 $GA/glibc-kernheaders-2.4-8.10.i386.rpm $GA/bison-1.35-6.i386.rpm \
	 $UPD/i386/glibc-common-2.3.2-27.9.7.i386.rpm \
	 $UPD/i686/glibc-2.3.2-27.9.7.i686.rpm \
	 $UPD/i386/glibc-devel-2.3.2-27.9.7.i386.rpm; do
  [ -f "$(basename $p)" ] || curl -sfLO "$p"
done
cd "$ROOT"

# Sandbox root: RH9 /usr/include, and a /usr/lib that holds the RH9 libraries
# and compiler next to symlinks to the host's /usr/lib entries (the host's
# /usr/lib is bound to /tmp/.rh9hostlib inside the sandbox).
R=$T/rh9
if [ ! -d "$R/lib" ]; then
  rm -rf "$R" && mkdir -p "$R"
  python3 tools/unrpm.py "$R/root" "$T"/rpms/*.rpm
  mkdir "$R/lib"
  cp -a "$R/root/usr/lib/." "$R/lib/"
  find "$R/root/lib" -maxdepth 1 \( -type f -o -type l \) -exec cp -a {} "$R/lib/" \;
  for e in /usr/lib/* /usr/lib/.[!.]*; do
    [ -e "$e" ] || [ -L "$e" ] || continue
    n=$(basename "$e")
    [ -e "$R/lib/$n" ] || [ -L "$R/lib/$n" ] || ln -s "/tmp/.rh9hostlib/$n" "$R/lib/$n"
  done
  for l in $(find "$R/lib" -maxdepth 1 -type l); do
    case $(readlink "$l") in
      ../../lib/*|/lib/*) ln -sfn "$(basename "$(readlink "$l")")" "$l" ;;
    esac
  done
  G=$R/lib/gcc-lib/i386-redhat-linux/3.2.2
  ln -sfn "$R/root/usr/bin/as" "$G/as"
  ln -sfn "$R/root/usr/bin/ld" "$G/ld"
fi
cat > "$T/bin/rh9" <<EOF
#!/bin/sh
# Run a command inside the Red Hat 9 i386 sandbox.
exec bwrap --dev-bind / / --ro-bind /usr/lib /tmp/.rh9hostlib --ro-bind "$R/lib" /usr/lib \\
  --ro-bind "$R/root/usr/include" /usr/include --tmpfs /usr/local \\
  --setenv PATH "$T/bin/psp:$R/root/usr/bin:/usr/bin:/bin" --setenv LC_ALL C \\
  --setenv BISON_SIMPLE "$R/root/usr/share/bison/bison.simple" setarch i686 "\$@"
EOF
cat > "$T/bin/run32" <<EOF
#!/bin/sh
# Run an i386 Linux program with the Red Hat 9 glibc.
exec "$R/lib/ld-linux.so.2" --library-path "$R/lib" "\$@"
EOF
chmod +x "$T/bin/rh9" "$T/bin/run32"

for v in 1.3.1 1.7.1; do
  if [ ! -d "$T/psp-gcc-$v" ]; then
    mkdir -p "$T/psp-gcc-$v"
    curl -sSfL "https://github.com/decompme/compilers/releases/download/compilers/psp-gcc-$v.tar.gz" | tar xz -C "$T/psp-gcc-$v"
  fi
done
# psp binutils (as used for every psp-gcc release we have), wrapped for the
# host and for the sandbox (tmp/toolchains/bin/psp, first in its PATH)
mkdir -p "$T/bin/psp"
for tool in as ld ar ranlib nm objdump objcopy; do
  f=$T/psp-gcc-1.3.1/bin/psp-$tool
  [ $tool = strip ] && f=$T/psp-gcc-1.3.1/bin/psp-gnu-strip
  printf '#!/bin/sh\nexec "%s/bin/run32" "%s" "$@"\n' "$T" "$f" > "$T/bin/psp-$tool"
  printf '#!/bin/sh\nexec "%s" "$@"\n' "$f" > "$T/bin/psp/psp-$tool"
  chmod +x "$T/bin/psp-$tool" "$T/bin/psp/psp-$tool"
done
printf '#!/bin/sh\nexec "%s/bin/run32" "%s" "$@"\n' "$T" "$T/psp-gcc-1.3.1/bin/psp-cpp" > "$T/bin/psp-cpp"
chmod +x "$T/bin/psp-cpp"
for v in 1.3.1 1.7.1; do
  printf '#!/bin/sh\nexec "%s/bin/run32" %s "$@"\n' "$T" "$(ls "$T"/psp-gcc-$v/lib/gcc-lib/psp/*/cc1)" > "$T/bin/cc1-$v-orig"
  chmod +x "$T/bin/cc1-$v-orig"
done

if [ ! -d "$T/binutils" ]; then
  (mkdir -p "$T/dl" && cd "$T/dl" && apt-get download binutils-mips-linux-gnu >/dev/null)
  dpkg-deb -x "$T"/dl/binutils-mips-linux-gnu_*.deb "$T/binutils"
  rm -rf "$T/dl"
fi
for tool in as ld objcopy objdump nm readelf; do
  printf '#!/bin/sh\nLD_LIBRARY_PATH=%s/usr/lib/x86_64-linux-gnu exec %s/usr/bin/mips-linux-gnu-%s "$@"\n' "$T/binutils" "$T/binutils" "$tool" > "$T/bin/mips-$tool"
  chmod +x "$T/bin/mips-$tool"
done
echo "toolchains ready in $T/bin"

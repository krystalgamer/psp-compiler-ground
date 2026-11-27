"""The modules in inputs/151_and_161.zip (and loose ones in inputs/), by target and module name."""
import hashlib
import zipfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ZIP = ROOT / "inputs" / "151_and_161.zip"
TOP = "151_and_161/"

# target -> {module name: member path}; UTST99332's BOOT.BIN is menu.prx.
FIXED = {
    "puzzle_bobble": {"BOOT": "puzzle_bobble/BOOT.BIN"},
    "sampler": {"sampler": "sampler.prx"},
    "UTST99261": {"BOOT": "UTST99261/BOOT.BIN"},
}

# modules given as single files in inputs/: target -> {module: file name}
LOOSE = {
    "bigbangbang": {"bigbangbang": "bigbangbang.prx"},
    "flowars": {"flowars": "flowars.prx"},
    "htmlviewer": {"htmlviewer": "171_184_htmlviewer.prx"},
}

# zips of decrypted modules in inputs/: target -> zip name; module = member stem
ZIPS = {
    "tony_libs": "tony_libs.zip",
    "psp184": "psp_161_to_184.zip",
    "umdt": "umdt.zip",
}


# zips whose members need explicit module names: target -> {module: (zip, member)}
# (psp_random_batch.zip: audiocodec and libatrac3plus are tony_libs' files, left out)
NAMED = {
    "rb": {
        "jp_BOOT": ("psp_random_batch.zip", "demo_disc_japan_modules/BOOT.BIN.dec"),
        "pal_BOOT": ("psp_random_batch.zip", "demo_disc_pal_modules/BOOT.BIN.dec"),
        "pal_mpeg": ("psp_random_batch.zip", "demo_disc_pal_modules/mpeg.prx.dec"),
        "pal_mpegbase": ("psp_random_batch.zip", "demo_disc_pal_modules/mpegbase.dec"),
        "pal_videocodec": ("psp_random_batch.zip", "demo_disc_pal_modules/videocodec.dec"),
        "gh_DEMOMOD": ("psp_random_batch.zip", "greatest_hits_module/DEMOMOD.PRX.dec"),
        "rs4_main": ("psp_random_batch.zip", "retail_sampler_four_module/main.prx.dec"),
    },
    # a game's modules (navi.zip): known libraries built by psp-gcc 1.11.0 /
    # 1.12.1.internal / 1.13.0.internal (gcc 3.3.6) and 4.0.x; print_msg has symbols
    "navi": {m: ("navi.zip", f) for m, f in [
        ("print_msg", "print_msg.prx.dec"), ("libpng", "libpng.prx.dec"), ("libz", "libz.prx.dec"),
        ("libjpeg", "libjpeg.prx.dec"), ("libblowfish", "libblowfish.prx.dec"), ("librsa", "librsa.prx.dec"),
        ("libpep", "libpep.prx.dec"), ("libsmojgb", "libsmojgb.prx.dec"), ("BOOT", "BOOT.BIN.dec"),
        ("libpsmfplayer", "libpsmfplayer.prx.wos"), ("psmf", "psmf.prx.wos")]},
    # pre-release firmware 1.02 selfboot: two builds of a loadexec test
    # program (1.5.1.internal, with DWARF) and lflash_write (no symbols)
    "selfboot": {
        "loadexec_test": ("pre_release_fws.zip", "102_selfboot/kd/loadexec_test.prx"),
        "zzzzdummy": ("pre_release_fws.zip", "102_selfboot/kd/zzzzdummy.dat"),
        "lflash_write": ("pre_release_fws.zip", "102_selfboot/lflash_write.prx"),
    },
}


def targets():
    out = {k: dict(v) for k, v in FIXED.items()}
    with zipfile.ZipFile(ZIP) as z:
        prx = sorted(n for n in z.namelist() if n.startswith(TOP + "UTST99332/PRX/") and n.endswith(".prx"))
    out["UTST99332"] = {Path(n).stem: n[len(TOP):] for n in prx}
    for t, mods in LOOSE.items():
        if all((ROOT / "inputs" / f).exists() for f in mods.values()):
            out[t] = {m: "file:" + f for m, f in mods.items()}
    for t, zname in ZIPS.items():
        if (ROOT / "inputs" / zname).exists():
            with zipfile.ZipFile(ROOT / "inputs" / zname) as z:
                out[t] = {n.split(".")[0]: f"zip:{zname}:{n}" for n in sorted(z.namelist()) if not n.endswith("/")}
    for t, mods in NAMED.items():
        if all((ROOT / "inputs" / z).exists() for z, _ in mods.values()):
            out[t] = {m: f"zip:{z}:{n}" for m, (z, n) in mods.items()}
    return out


def read(target, module):
    member = targets()[target][module]
    if member.startswith("file:"):
        return (ROOT / "inputs" / member[5:]).read_bytes()
    if member.startswith("zip:"):
        _, zname, name = member.split(":", 2)
        with zipfile.ZipFile(ROOT / "inputs" / zname) as z:
            return z.read(name)
    with zipfile.ZipFile(ZIP) as z:
        return z.read(TOP + member)


def extract(target, module):
    data = read(target, module)
    dest = ROOT / "tmp" / "baserom" / target / f"{module}.prx"
    dest.parent.mkdir(parents=True, exist_ok=True)
    sha = ROOT / "config" / target / f"{module}.sha1"
    if sha.exists() and sha.read_text().split()[0] != hashlib.sha1(data).hexdigest():
        raise SystemExit(f"sha1 mismatch for {target}/{module}")
    dest.write_bytes(data)
    return dest


if __name__ == "__main__":
    import sys
    if len(sys.argv) == 3:
        print(extract(sys.argv[1], sys.argv[2]))
    else:
        for t, mods in targets().items():
            for m in mods:
                print(t, m)

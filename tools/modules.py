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
}

# zips of decrypted modules in inputs/: target -> zip name; module = member stem
ZIPS = {
    "tony_libs": "tony_libs.zip",
    "psp184": "psp_161_to_184.zip",
    "umdt": "umdt.zip",
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

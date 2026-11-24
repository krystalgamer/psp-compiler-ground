"""The modules in inputs/151_and_161.zip, by target and module name."""
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


def targets():
    out = {k: dict(v) for k, v in FIXED.items()}
    with zipfile.ZipFile(ZIP) as z:
        prx = sorted(n for n in z.namelist() if n.startswith(TOP + "UTST99332/PRX/") and n.endswith(".prx"))
    out["UTST99332"] = {Path(n).stem: n[len(TOP):] for n in prx}
    return out


def read(target, module):
    member = targets()[target][module]
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

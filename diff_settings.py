def apply(config, args):
    config["arch"] = "mipsee"
    config["baseimg"] = "disks/SCUS_971.01.rom"
    config["myimg"] = "build/SCUS_971.01.rom"
    config["mapfile"] = "build/SCUS_971.01.map"
    config["source_directories"] = ["."]
    config["objdump_executable"] = "mips-linux-gnu-objdump"

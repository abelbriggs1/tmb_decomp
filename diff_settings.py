def apply(config, args):
    config["arch"] = "mipsel"
    config["baseimg"] = "disks/SCUS_971.01"
    config["myimg"] = "build/SCUS_971.01"
    config["mapfile"] = "build/SCUS_971.01.map"
    config["source_directories"] = ["."]
    config["objdump_executable"] = "mips-linux-gnu-objdump"

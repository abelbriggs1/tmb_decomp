def apply(config, args):
    config["arch"] = "mipsel"
    config["baseimg"] = "disks/SCUS_971.01"
    config["myimg"] = "build/TMB_US.elf.final"
    config["mapfile"] = "build/TMB_US.map"
    config["source_directories"] = ["."]
    config["objdump_executable"] = "mips-linux-gnu-objdump"

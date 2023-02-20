#
# Copyright (C) 2017-2020 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# See LICENSE in the top level directory for licensing details
#
# rev-test-ex1.py
#

import os
import sst

# Define SST core options
sst.setProgramOption("timebase", "1ps")
sst.setProgramOption("stopAtCycle", "0s")

# Tell SST what statistics handling we want
sst.setStatisticLoadLevel(4)

max_addr_gb = 1

        #"machine" : "[0:RV64IMAF]",                      # Core:Config; RV32I for core 0
        #"machine" : "[0:RV32I]",                      # Core:Config; RV32I for core 0
        #"program" : os.getenv("REV_EXE", "fir_hilbert_int.exe"),  # Target executable
#        "program" : os.getenv("REV_EXE", "ex1_int.exe"),  # Target executable
# Define the simulation components
comp_cpu = sst.Component("cpu", "revcpu.RevCPU")
comp_cpu.addParams({
	"verbose" : 4,                                # Verbosity
        "numCores" : 1,                               # Number of cores
	"clock" : "1.0GHz",                           # Clock
        "memSize" : 1024*1024*1024*8,                   # Memory size in bytes
        "machine" : "[0:RV64IMAFD]",                      # Core:Config; RV32I for core 0
        "startAddr" : "[0:0x000]",               # Starting address for core 0
        "memCost" : "[0:5:40]",                       # Memory loads required 1-10 cycles
        "program" : os.getenv("REV_EXE", "ex1.exe"),  # Target executable
        "splash" : 1                                  # Display the splash message
})

sst.setStatisticOutput("sst.statOutputCSV")
sst.enableAllStatisticsForAllComponents()

# EOF

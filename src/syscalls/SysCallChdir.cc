//
// SysCallChdir.cc
//
// Copyright (C) 2017-2021 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//
#include "SysCallChdir.h"

#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>

namespace SST { namespace RevCPU {

template<>
template<>
bool ChdirParameters<Riscv32>::get<std::string>(const size_t parameter_index, std::string& param) {
    if(parameter_index == 0) {
        param = pth;
        return true;
    }

    return false;
}

template<>
template<>
bool ChdirParameters<Riscv64>::get<std::string>(const size_t parameter_index, std::string& param) {
    if(parameter_index == 0) {
        param = pth;
        return true;
    }

    return false;
}

template<>
template<>
bool ChdirParameters<Riscv128>::get<std::string>(const size_t parameter_index, std::string& param) {
    if(parameter_index == 0) {
        param = pth;
        return true;
    }

    return false;
}

template<>
template<>
void Chdir<Riscv32>::invoke<int>(RevRegFile const& memregfile, RevMem const& revmemory, int & value) {
    if(parameters.count() == 1) {

        std::string pth;

        bool has_values = parameters.get<std::string>(0, pth);

        if(has_values) {
            success = true;
            value = chdir(pth.c_str());
        }
    }
}

template<>
template<>
void Chdir<Riscv64>::invoke<int>(RevRegFile const& memregfile, RevMem const& revmemory, int & value) {
    if(parameters.count() == 1) {

        std::string pth;

        bool has_values = parameters.get<std::string>(0, pth);

        if(has_values) {
            success = true;
            value = chdir(pth.c_str());
        }
    }
}

template<>
template<>
void Chdir<Riscv128>::invoke<int>(RevRegFile const& memregfile, RevMem const& revmemory, int & value) {
    if(parameters.count() == 1) {

        std::string pth;

        bool has_values = parameters.get<std::string>(0, pth);

        if(has_values) {
            success = true;
            value = chdir(pth.c_str());
        }
    }
}

} /* end namespace RevCPU */ } // end namespace SST
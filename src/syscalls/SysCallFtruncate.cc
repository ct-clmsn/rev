//
// SysCallFtruncate.cc
//
// Copyright (C) 2017-2021 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//
#include "SysCallFtruncate.h"

#include <unistd.h>

namespace SST { namespace RevCPU {

    template<>
    template<>
    bool FtruncateParameters<Riscv32>::get<int>(const size_t parameter_index, int& param) {
        if(parameter_index == 0) {
            param = fildes;
            return true;
        }

        return false;
    }

    template<>
    template<>
    bool FtruncateParameters<Riscv64>::get<int>(const size_t parameter_index, int& param) {
        if(parameter_index == 0) {
            param = fildes;
            return true;
        }

        return false;
    }

    template<>
    template<>
    bool FtruncateParameters<Riscv128>::get<int>(const size_t parameter_index, int& param) {
        if(parameter_index == 0) {
            param = fildes;
            return true;
        }

        return false;
    }

    template<>
    template<>
    bool FtruncateParameters<Riscv32>::get<off_t>(const size_t parameter_index, off_t& param) {
        if(parameter_index == 1) {
            param = length;
            return true;
        }

        return false;
    }

    template<>
    template<>
    bool FtruncateParameters<Riscv64>::get<off_t>(const size_t parameter_index, off_t& param) {
        if(parameter_index == 1) {
            param = length;
            return true;
        }

        return false;
    }

    template<>
    template<>
    bool FtruncateParameters<Riscv128>::get<off_t>(const size_t parameter_index, off_t& param) {
        if(parameter_index == 1) {
            param = length;
            return true;
        }

        return false;
    }

template<>
template<>
void Ftruncate<Riscv32>::invoke<int>(RevRegFile const& memregfile, RevMem const& revmemory, int & value) {
    if(parameters.count() == 2) {

        int fildes;
        off_t length;

        bool has_values[2] = { false, false };
        has_values[0] = parameters.get<int>(0, fildes);
        has_values[1] = parameters.get<off_t>(1, length);


        if(has_values[0] && has_values[1]) {
            success = true;
            value = ftruncate(fildes, length);
        }
    }
}

template<>
template<>
void Ftruncate<Riscv64>::invoke<int>(RevRegFile const& memregfile, RevMem const& revmemory, int & value) {
    if(parameters.count() == 2) {

        int fildes;
        off_t length;

        bool has_values[2] = { false, false };
        has_values[0] = parameters.get<int>(0, fildes);
        has_values[1] = parameters.get<off_t>(1, length);


        if(has_values[0] && has_values[1]) {
            success = true;
            value = ftruncate(fildes, length);
        }
    }
}

template<>
template<>
void Ftruncate<Riscv128>::invoke<int>(RevRegFile const& memregfile, RevMem const& revmemory, int & value) {
    if(parameters.count() == 2) {

        int fildes;
        off_t length;

        bool has_values[2] = { false, false };
        has_values[0] = parameters.get<int>(0, fildes);
        has_values[1] = parameters.get<off_t>(1, length);


        if(has_values[0] && has_values[1]) {
            success = true;
            value = ftruncate(fildes, length);
        }
    }
}

} /* end namespace RevCPU */ } // end namespace SST

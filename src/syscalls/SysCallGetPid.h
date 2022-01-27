//
// SysCallGetPid.h
//
// Copyright (C) 2017-2021 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//
#pragma once
#ifndef __SYSTEMCALLGETPID_H__
#define __SYSTEMCALLGETPID_H__

#include "SystemCallInterface.h"
#include <type_traits>
#include <sys/types.h>

namespace SST { namespace RevCPU {

class GetPidSystemCallParameters : public virtual SystemCallParameterInterface {
    
    public:

    GetPidSystemCallParameters() : SystemCallParameterInterface() {}

    size_t count() override;

    template<typename ParameterType>
    bool get(const size_t parameter_index, ParameterType & param);

    template<typename ParameterType>
    bool get(const size_t parameter_index, void_t & param);
};

template<bool IsRiscv32>
class GetPidSystemCall : public virtual SystemCallInterface<IsRiscv32> {

    using RiscvModeIntegerType = typename std::conditional<IsRiscv32, std::uint32_t, std::uint64_t>::type;

    public:

    const static RiscvModeIntegerType code_value = static_cast<RiscvModeIntegerType>(172);

    GetPidSystemCall() {}

    RiscvModeIntegerType code() override;
    
    // always returns false
    //
    template<typename ReturnType>
    void invoke(SystemCallParameterInterface & parameters, ReturnType & value);

    // returns true
    //
    template<>
    void invoke(SystemCallParameterInterface & parameters, void_t & value);
};

} /* end namespace RevCPU */ } // end namespace SST

#endif

// EOF
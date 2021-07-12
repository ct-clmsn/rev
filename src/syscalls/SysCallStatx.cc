//
// SysCallStatx.cc
//
// Copyright (C) 2017-2021 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//
#include "SysCallStatx.h"

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

namespace SST { namespace RevCPU {

    template<>
    template<>
    bool StatxParameters<Riscv32>::get<int>(const size_t parameter_index, int& param) {
        if(parameter_index == 0) {
            param = dirfd;
            return true;
        }
        else if(parameter_index == 2) {
            param = flags;
            return true;
        }

        return false;
    }

    template<>
    template<>
    bool StatxParameters<Riscv64>::get<int>(const size_t parameter_index, int& param) {
        if(parameter_index == 0) {
            param = dirfd;
            return true;
        }
        else if(parameter_index == 2) {
            param = flags;
            return true;
        }

        return false;
    }

    template<>
    template<>
    bool StatxParameters<Riscv128>::get<int>(const size_t parameter_index, int& param) {
        if(parameter_index == 0) {
            param = dirfd;
            return true;
        }
        else if(parameter_index == 2) {
            param = flags;
            return true;
        }

        return false;
    }

    template<>
    template<>
    bool StatxParameters<Riscv32>::get<const char*>(const size_t parameter_index, const char* & param) {
        if(parameter_index == 1) {
            param = pathname;
            return true;
        }

        return false;
    }

    template<>
    template<>
    bool StatxParameters<Riscv64>::get<const char*>(const size_t parameter_index, const char* & param) {
        if(parameter_index == 1) {
            param = pathname;
            return true;
        }

        return false;
    }

    template<>
    template<>
    bool StatxParameters<Riscv128>::get<const char*>(const size_t parameter_index, const char* & param) {
        if(parameter_index == 1) {
            param = pathname;
            return true;
        }

        return false;
    }

    template<>
    template<>
    bool StatxParameters<Riscv32>::get<unsigned int>(const size_t parameter_index, unsigned int & param) {
        if(parameter_index == 3) {
            param = mask;
            return true;
        }

        return false;
    }

    template<>
    template<>
    bool StatxParameters<Riscv64>::get<unsigned int>(const size_t parameter_index, unsigned int & param) {
        if(parameter_index == 3) {
            param = mask;
            return true;
        }

        return false;
    }

    template<>
    template<>
    bool StatxParameters<Riscv128>::get<unsigned int>(const size_t parameter_index, unsigned int & param) {
        if(parameter_index == 3) {
            param = mask;
            return true;
        }

        return false;
    }

    template<>
    template<>
    bool StatxParameters<Riscv32>::get<statx_t*>(const size_t parameter_index, statx_t * & param) {
        if(parameter_index == 4) {
            param = statxbuf;
            return true;
        }

        return false;
    }

    template<>
    template<>
    bool StatxParameters<Riscv64>::get<statx_t*>(const size_t parameter_index, statx_t * & param) {
        if(parameter_index == 4) {
            param = statxbuf;
            return true;
        }

        return false;
    }

    template<>
    template<>
    bool StatxParameters<Riscv128>::get<statx_t*>(const size_t parameter_index, statx_t * & param) {
        if(parameter_index == 4) {
            param = statxbuf;
            return true;
        }

        return false;
    }

template<>
template<>
void Statx<Riscv32>::invoke<int>(RevRegFile const& memregfile, RevMem const& revmemory, int & value) {
    if(parameters.count() == 5) {

        int dirfd;
        const char * pathname;
        int flags;
        unsigned int mask;
        statx_t * statxbuf;

        bool has_values[5] = { false, false, false, false, false };
        has_values[0] = parameters.get<int>(0, dirfd);
        has_values[1] = parameters.get<const char *>(1, pathname);
        has_values[2] = parameters.get<int>(2, flags);
        has_values[3] = parameters.get<unsigned int>(3, mask);
        has_values[4] = parameters.get<statx_t *>(4, statxbuf);

        if(has_values[0] && has_values[1] && has_values[2] && has_values[3]  && has_values[4]) {
            success = true;
            value = statx(dirfd, pathname, flags, mask, statxbuf);
        }
    }
}

template<>
template<>
void Statx<Riscv64>::invoke<int>(RevRegFile const& memregfile, RevMem const& revmemory, int & value) {
    if(parameters.count() == 5) {

        int dirfd;
        const char * pathname;
        int flags;
        unsigned int mask;
        statx_t * statxbuf;

        bool has_values[5] = { false, false, false, false, false };
        has_values[0] = parameters.get<int>(0, dirfd);
        has_values[1] = parameters.get<const char *>(1, pathname);
        has_values[2] = parameters.get<int>(2, flags);
        has_values[3] = parameters.get<unsigned int>(3, mask);
        has_values[4] = parameters.get<statx_t *>(4, statxbuf);

        if(has_values[0] && has_values[1] && has_values[2] && has_values[3]  && has_values[4]) {
            success = true;
            value = statx(dirfd, pathname, flags, mask, statxbuf);
        }
    }
}

template<>
template<>
void Statx<Riscv128>::invoke<int>(RevRegFile const& memregfile, RevMem const& revmemory, int & value) {
    if(parameters.count() == 5) {

        int dirfd;
        const char * pathname;
        int flags;
        unsigned int mask;
        statx_t * statxbuf;

        bool has_values[5] = { false, false, false, false, false };
        has_values[0] = parameters.get<int>(0, dirfd);
        has_values[1] = parameters.get<const char *>(1, pathname);
        has_values[2] = parameters.get<int>(2, flags);
        has_values[3] = parameters.get<unsigned int>(3, mask);
        has_values[4] = parameters.get<statx_t *>(4, statxbuf);

        if(has_values[0] && has_values[1] && has_values[2] && has_values[3]  && has_values[4]) {
            success = true;
            value = statx(dirfd, pathname, flags, mask, statxbuf);
        }
    }
}

} /* end namespace RevCPU */ } // end namespace SST
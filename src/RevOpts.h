//
// _RevOpts_h_
//
// Copyright (C) 2017-2023 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#ifndef _SST_REVCPU_REVOPTS_H_
#define _SST_REVCPU_REVOPTS_H_

// -- SST Headers
#include <sst/core/sst_config.h>
#include <sst/core/component.h>

// -- Standard Headers
#include <cinttypes>
#include <map>
#include <vector>
#include <string>

namespace SST::RevCPU {
  class RevOpts;
}

using namespace SST::RevCPU;

namespace SST {
  namespace RevCPU {
    class RevOpts{
    public:
      /// RevOpts: options constructor
      RevOpts( unsigned NumCores, const int Verbosity );

      /// RevOpts: options destructor
      ~RevOpts();

      /// RevOpts: retrieve the number of configured cores
      unsigned GetNumCores() { return numCores; }

      /// RevOpts: retrieve the verbosity level
      int GetVerbosity() { return verbosity; }

      /// RevOpts: initialize the set of starting addresses
      bool InitStartAddrs( std::vector<std::string> StartAddrs );

      /// RevOpts: initialize the set of potential starting symbols
      bool InitStartSymbols( std::vector<std::string> StartSymbols );

      /// RevOpts: initialize the set of machine models
      bool InitMachineModels( std::vector<std::string> Machines );

      /// RevOpts: initalize the set of instruction tables
      bool InitInstTables( std::vector<std::string> InstTables );

      /// RevOpts: initialize the memory latency cost tables
      bool InitMemCosts( std::vector<std::string> MemCosts );

      /// RevOpts: retrieve the start address for the target core
      bool GetStartAddr( unsigned Core, uint64_t &StartAddr );

      /// RevOpts: retrieve the start symbol for the target core
      bool GetStartSymbol( unsigned Core, std::string &Symbol );

      /// RevOpts: retrieve the machine model string for the target core
      bool GetMachineModel( unsigned Core, std::string &MachModel );

      /// RevOpts: retrieve instruction table for the target core
      bool GetInstTable( unsigned Core, std::string &Table );

      /// RevOpts: retrieve the memory cost range for the target core
      bool GetMemCost( unsigned Core, unsigned &Min, unsigned &Max );

    private:
      unsigned numCores;                      ///< RevOpts: number of initialized cores
      int verbosity;                          ///< RevOpts: verbosity level

      std::map<unsigned,uint64_t> startAddr;  ///< RevOpts: map of core id to starting address
      std::map<unsigned,std::string> startSym;///< RevOpts: map of core id to starting symbol
      std::map<unsigned,std::string> machine; ///< RevOpts: map of core id to machine model
      std::map<unsigned,std::string> table;   ///< RevOpts: map of core id to inst table

      std::vector<std::pair<unsigned,unsigned>> memCosts; ///< RevOpts: vector of memory cost ranges

      ///< RevOpts; splits a string into tokens
      void splitStr(const std::string& s,char c,std::vector<std::string>& v);

    }; // class RevOpts
  } // namespace RevCPU
} // namespace SST

#endif

// EOF

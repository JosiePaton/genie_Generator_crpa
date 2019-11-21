//____________________________________________________________________________
/*!

\class    genie::HEDISInteractionListGenerator

\brief    Concrete implementations of the InteractionListGeneratorI interface.
          Generate a list of all the Interaction (= event summary) objects that
          can be generated by the HEDIS EventGenerator.

\author   Alfonso Garcia <alfonsog \at nikhef.nl>
          NIKHEF

\created  August 28, 2019

\cpright  Copyright (c) 2003-2018, The GENIE Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _HEDIS_INTERACTION_LIST_GENERATOR_H_
#define _HEDIS_INTERACTION_LIST_GENERATOR_H_

#include "Framework/EventGen/InteractionListGeneratorI.h"
#include "Framework/Interaction/HEDISChannel.h"

namespace genie {

class Interaction;

class HEDISInteractionListGenerator : public InteractionListGeneratorI {

public :
  HEDISInteractionListGenerator();
  HEDISInteractionListGenerator(string config);
 ~HEDISInteractionListGenerator();

  // implement the InteractionListGeneratorI interface
  InteractionList * CreateInteractionList(const InitialState & init) const;

  // overload the Algorithm::Configure() methods to load private data
  // members from configuration options
  void Configure(const Registry & config);
  void Configure(string config);

private:

  void AddFinalStateInfo(Interaction * interaction, HEDISQrkChannel_t hedischan) const;
  void LoadConfigData(void);
  
  bool fIsCC;
  bool fIsNC;

};

}      // genie namespace

#endif // _HEDIS_INTERACTION_LIST_GENERATOR_H_

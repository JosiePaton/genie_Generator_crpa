//____________________________________________________________________________
/*!

\class    genie::LeptoHadronization

\brief    Provides access to the LEPTO hadronization models. \n
          Is a concrete implementation of the HadronizationModelI interface.

\author   Alfonso Garcia <alfonsog \at nikhef.nl>
          NIKHEF (Amsterdam)

\created  October 18, 2019

\cpright  Copyright (c) 2003-2018, The GENIE Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _LEPTO_HADRONIZATION_H_
#define _LEPTO_HADRONIZATION_H_

#include <TPythia6.h>

#include "Framework/EventGen/EventRecordVisitorI.h"
#include "Framework/Interaction/Interaction.h"

namespace genie {

class GHepParticle;

class LeptoHadronization : public EventRecordVisitorI {

public:
  LeptoHadronization();
  LeptoHadronization(string config);
  virtual ~LeptoHadronization();

  //-- implement the HadronizationModelI interface
  void ProcessEventRecord(GHepRecord * event) const;

  //-- overload the Algorithm::Configure() methods to load private data
  //   members from configuration options
  void Configure(const Registry & config);
  void Configure(string config);

private:

  void           Initialize       (void)               const;
  TClonesArray * Hadronize        (const Interaction*) const;
  void           LoadConfig       (void);

  mutable TPythia6 * fPythia;   ///< PYTHIA6 wrapper class

  //-- configuration parameters
  int    fMaxIterHad;         // Maxmium number of iterations to look for a combination of hadrons
  double fPrimordialKT;       // Width of Gaussian distribution for the primordial transverse momentum kT of partons in the nucleon.
  double fRemnantPT;          // Width of Gaussian distribution in transverse momentum when a non-trivial target remnant is split into two particles
  double fMinESinglet;        // It is, with quark masses added, used to define the minimum allowable energy of a colour-singlet parton system.
  bool   fPromptPythiaList;   // Print the list of particles from PYTHIA
  double fWmin;               // Minimum value of W

};

}         // genie namespace

#endif    // _LEPTO_HADRONIZATION__H_


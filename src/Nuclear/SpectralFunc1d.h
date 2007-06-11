//____________________________________________________________________________
/*!

\class    genie::SpectralFunc1d

\brief    Simpler approach to using spectral functions.
	  A beta version.
          Implements the NuclearModelI interface.

\ref      

\author   Costas Andreopoulos <C.V.Andreopoulos@rl.ac.uk>
          CCLRC, Rutherford Appleton Laboratory

\created  October 09, 2004

*/
//____________________________________________________________________________

#ifndef _SPECTRAL_FUNCTION_1D_H_
#define _SPECTRAL_FUNCTION_1D_H_

#include <map>

#include "Nuclear/NuclearModelI.h"

using std::map;

namespace genie {

class Spline;
class SpectralFunc1d : public NuclearModelI {

public:
  SpectralFunc1d();
  SpectralFunc1d(string config);
  virtual ~SpectralFunc1d();

  //-- implement the NuclearModelI interface
  bool     GenerateNucleon (const Target & t) const;
  double   Prob            (double p, double w, const Target & t) const;

  //-- override the Algorithm::Configure methods to load configuration
  //   data to private data members
  void Configure (const Registry & config);
  void Configure (string param_set);

private:
  void LoadConfig (void);
  void CleanUp    (void);
  
  // Spectral function data
  // Hopefully, analytical expressions for spectral functions will become available soon.
  //
  bool fUseFGMRemovalE;
  map<int, Spline *> fSFk;     ///< All available spectral funcs integrated over removal energy
  map<int, Spline *> fSFw;     ///< Average nucleon removal as a function of pF - computed from the spectral function
  map<int, double>   fNucRmvE; ///< Removal energies as used in FG model
  map<int, double>   fMaxProb; ///< Max SF(k) probability used in rejection method
};

}         // genie namespace
#endif    // _SPECTRAL_FUNCTION_1D_H_


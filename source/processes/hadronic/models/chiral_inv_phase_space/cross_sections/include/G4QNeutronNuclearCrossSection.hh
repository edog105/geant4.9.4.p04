//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// GEANT4 tag $Name: not supported by cvs2svn $
//
//
// GEANT4 physics class: G4QNeutronNuclearCrossSection -- header file
// Created: M.V. Kossov, CERN/ITEP(Moscow), 17-May-2009
// The last update: M.V. Kossov, CERN/ITEP (Moscow) 21-May-2009
//
// **********************************************************************
// This Header is a part of the CHIPS physics package (author: M. Kosov)
// ------------------------------------------------------------------------
// Short description: CHIPS cross-sections for neutron-nuclear interactions
// ------------------------------------------------------------------------

#ifndef G4QNeutronNuclearCrossSection_h
#define G4QNeutronNuclearCrossSection_h 1

#include "G4ParticleTable.hh"
#include "G4NucleiProperties.hh"
#include <vector>
#include "G4VQCrossSection.hh"

class G4QNeutronNuclearCrossSection : public G4VQCrossSection
{
protected:

  G4QNeutronNuclearCrossSection()  {}

public:

  ~G4QNeutronNuclearCrossSection();

  static G4VQCrossSection* GetPointer(); // Gives a pointer to this singletone

  // At present momentum (pMom) in MeV/c, CS in mb (@@ Units)
  virtual G4double GetCrossSection(G4bool fCS, G4double pMom, G4int tgZ, G4int tgN,
                                   G4int pPDG=2112);

  G4double CalculateCrossSection(G4bool CS, G4int F, G4int I, G4int PDG, G4int Z,
                                 G4int N, G4double Momentum);

private:
  G4double CrossSectionLin(G4int targZ, G4int targN, G4double P);
  G4double CrossSectionLog(G4int targZ, G4int targN, G4double lP);
  G4double CrossSectionFormula(G4int targZ, G4int targN, G4double P, G4double lP);
// Body
private:
  static G4double  lastSig; // Last value of the Cross Section
  static G4double* lastLEN; // Pointer to the last array of LowEnergy cross sections
  static G4double* lastHEN; // Pointer to the last array of HighEnergy cross sections
  static G4double  lastE;   // Last used in the cross section Energy
  static G4int     lastPDG; // The last projectile PDG
  static G4int     lastN;   // The last N of calculated nucleus
  static G4int     lastZ;   // The last Z of calculated nucleus
  static G4double  lastP;   // Last used in the cross section Momentum
  static G4double  lastTH;  // Last value of the Momentum Threshold
  static G4double  lastCS;  // Last value of the Cross Section
  static G4int     lastI;   // The last position in the DAMDB
  static G4double  HEthresh;  // High energy threshold parameter for the CS calculation
  static std::vector<G4double*>* LEN;  // Vector of pointers to LowEnNeutronCrossSection
  static std::vector<G4double*>* HEN;  // Vector of pointers to HighEnNeutronCrossSection
};

#endif

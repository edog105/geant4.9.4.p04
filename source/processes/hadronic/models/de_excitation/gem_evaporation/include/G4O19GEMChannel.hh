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
// $Id$
//
// Hadronic Process: Nuclear De-excitations
// by V. Lara (Sept. 2001)
//


#ifndef G4O19GEMChannel_h
#define G4O19GEMChannel_h 1

#include "G4GEMChannel.hh"
#include "G4O19GEMCoulombBarrier.hh"
#include "G4O19GEMProbability.hh"

class G4O19GEMChannel : public G4GEMChannel
{
public:
  // only available constructor
  G4O19GEMChannel() : G4GEMChannel(19,8,"O19",
				   &theEvaporationProbability,
				   &theCoulombBarrier)
  {
    theEvaporationProbability.SetCoulomBarrier(&theCoulombBarrier);
  }
  
  // destructor
  ~G4O19GEMChannel() {};
  
private:
  const G4O19GEMChannel & operator=(const G4O19GEMChannel & right);  
    
  G4O19GEMChannel(const G4O19GEMChannel & right);
  
public:
  G4bool operator==(const G4O19GEMChannel & right) const;
  G4bool operator!=(const G4O19GEMChannel & right) const;
    
private:
  
  G4O19GEMCoulombBarrier theCoulombBarrier;
	
  G4O19GEMProbability theEvaporationProbability;
  
};
#endif


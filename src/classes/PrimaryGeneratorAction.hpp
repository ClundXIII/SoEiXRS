#ifndef SoEiXRS_CLASSES_PrimaryGeneratorAction_HPP
#define SoEiXRS_CLASSES_PrimaryGeneratorAction_HPP 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

#include <random>

class G4ParticleGun;
class G4Event;
class G4Box;

namespace SoEiXRS {

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
  public:
    PrimaryGeneratorAction(double energy, double energyFluc);
    virtual ~PrimaryGeneratorAction();

    // method from the base class
    virtual void GeneratePrimaries(G4Event*);         
  
    // method to access particle gun
    const G4ParticleGun* GetParticleGun() const { return fParticleGun; }
  
  private:
    G4ParticleGun*  fParticleGun; // pointer a to G4 gun class
    G4Box* fEnvelopeBox;

    std::default_random_engine de; // the rng for the energy, simple gauss
    std::normal_distribution<double> energyDist;

};

} /* namespace SoEiXRS */

#endif /* SoEiXRS_CLASSES_PrimaryGeneratorAction_HPP */

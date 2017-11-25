#ifndef Danse2_h
#define Danse2_h

#include <Arduino.h>
#include "param.h"

#define NB_STEPS_2 6

typedef Step Servos2[NOMBRE_SERVO];
typedef Servos2 DanseSteps2[NB_STEPS_2];

class Danse2 {
  public:
    Danse2();
    boolean nextStep();
    Step getCurrentStep(byte servo);
    void init();
  private:
    DanseSteps2 _danse;
    byte _currentStep;
    byte _numberOfSteps;
};

#endif



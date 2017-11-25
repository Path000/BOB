#ifndef Danse1_h
#define Danse1_h

#include <Arduino.h>
#include "param.h"

#define NB_STEPS_1 6

typedef Step Servos1[NOMBRE_SERVO];
typedef Servos1 DanseSteps1[NB_STEPS_1];

class Danse1 {
  public:
    Danse1();
    boolean nextStep();
    Step getCurrentStep(byte servo);
    void init();
  private:
    DanseSteps1 _danse;
    byte _currentStep;
    byte _numberOfSteps;
};

#endif

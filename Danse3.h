#ifndef Danse3_h
#define Danse3_h

#include <Arduino.h>
#include "param.h"

#define NB_STEPS_3 4

typedef Step Servos3[NOMBRE_SERVO];
typedef Servos3 DanseSteps3[NB_STEPS_3];

class Danse3 {
  public:
    Danse3();
    boolean nextStep();
    Step getCurrentStep(byte servo);
    void init();
  private:
    DanseSteps3 _danse;
    byte _currentStep;
    byte _numberOfSteps;
};

#endif


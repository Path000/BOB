#include "Danse1.h"

Danse1::Danse1() {
  _numberOfSteps = NB_STEPS_1;

  _danse[0][SERVO_PIED_GAUCHE] = {MAX_PIED_GAUCHE, 1000};
  _danse[0][SERVO_PIED_DROIT] = {MAX_PIED_DROIT, 1000};
  _danse[0][SERVO_HANCHE_GAUCHE] = {MID_HANCHE_GAUCHE, 0};
  _danse[0][SERVO_HANCHE_DROITE] = {MID_HANCHE_DROIT, 0};
 
  _danse[1][SERVO_PIED_GAUCHE] = {MIN_PIED_GAUCHE, 500};
  _danse[1][SERVO_PIED_DROIT] = {MAX_PIED_DROIT, 0};
  _danse[1][SERVO_HANCHE_GAUCHE] = {MID_HANCHE_GAUCHE, 0};
  _danse[1][SERVO_HANCHE_DROITE] = {MID_HANCHE_DROIT, 0};

  _danse[2][SERVO_PIED_GAUCHE] = {MID_PIED_GAUCHE, 100};
  _danse[2][SERVO_PIED_DROIT] = {MAX_PIED_DROIT, 0};
  _danse[2][SERVO_HANCHE_GAUCHE] = {MID_HANCHE_GAUCHE, 0};
  _danse[2][SERVO_HANCHE_DROITE] = {MID_HANCHE_DROIT, 0};

  _danse[3][SERVO_PIED_GAUCHE] = {MIN_PIED_GAUCHE, 100};
  _danse[3][SERVO_PIED_DROIT] = {MAX_PIED_DROIT, 0};
  _danse[3][SERVO_HANCHE_GAUCHE] = {MID_HANCHE_GAUCHE, 0};
  _danse[3][SERVO_HANCHE_DROITE] = {MID_HANCHE_DROIT, 0};

  _danse[4][SERVO_PIED_GAUCHE] = {MID_PIED_GAUCHE, 100};
  _danse[4][SERVO_PIED_DROIT] = {MAX_PIED_DROIT, 0};
  _danse[4][SERVO_HANCHE_GAUCHE] = {MID_HANCHE_GAUCHE, 0};
  _danse[4][SERVO_HANCHE_DROITE] = {MID_HANCHE_DROIT, 0};

  _danse[5][SERVO_PIED_GAUCHE] = {MID_PIED_GAUCHE, 0};
  _danse[5][SERVO_PIED_DROIT] = {MID_PIED_DROIT, 1500};
  _danse[5][SERVO_HANCHE_GAUCHE] = {MID_HANCHE_GAUCHE, 0};
  _danse[5][SERVO_HANCHE_DROITE] = {MID_HANCHE_DROIT, 0};
}

Step Danse1::getCurrentStep(byte servo) {
  return _danse[_currentStep][servo];
}

boolean Danse1::nextStep() {
  _currentStep++;
  if(_currentStep >= _numberOfSteps) {
    return false;
  }
  return true;
}


void Danse1::init() {
  _currentStep = 0;
}


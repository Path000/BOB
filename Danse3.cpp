#include "Danse3.h"

Danse3::Danse3() {
  _numberOfSteps = NB_STEPS_3;

  _danse[0][SERVO_PIED_GAUCHE] = {MID_PIED_GAUCHE, 0};
  _danse[0][SERVO_PIED_DROIT] = {MID_PIED_DROIT, 0};
  _danse[0][SERVO_HANCHE_GAUCHE] = {MAX_HANCHE_GAUCHE, 1000};
  _danse[0][SERVO_HANCHE_DROITE] = {MAX_HANCHE_DROIT, 1000};

  _danse[1][SERVO_PIED_GAUCHE] = {MID_PIED_GAUCHE, 0};
  _danse[1][SERVO_PIED_DROIT] = {MID_PIED_DROIT, 0};
  _danse[1][SERVO_HANCHE_GAUCHE] = {MIN_HANCHE_GAUCHE, 500};
  _danse[1][SERVO_HANCHE_DROITE] = {MIN_HANCHE_DROIT, 500};

  _danse[2][SERVO_PIED_GAUCHE] = {MID_PIED_GAUCHE, 0};
  _danse[2][SERVO_PIED_DROIT] = {MID_PIED_DROIT, 0};
  _danse[2][SERVO_HANCHE_GAUCHE] = {MAX_HANCHE_GAUCHE, 500};
  _danse[2][SERVO_HANCHE_DROITE] = {MAX_HANCHE_DROIT, 500};

  _danse[3][SERVO_PIED_GAUCHE] = {MID_PIED_GAUCHE, 0};
  _danse[3][SERVO_PIED_DROIT] = {MID_PIED_DROIT, 0};
  _danse[3][SERVO_HANCHE_GAUCHE] = {MID_HANCHE_GAUCHE, 1000};
  _danse[3][SERVO_HANCHE_DROITE] = {MID_HANCHE_DROIT, 1000};
}

Step Danse3::getCurrentStep(byte servo) {
  return _danse[_currentStep][servo];
}

boolean Danse3::nextStep() {
  _currentStep++;
  if(_currentStep >= _numberOfSteps) {
    return false;
  }
  return true;
}


void Danse3::init() {
  _currentStep = 0;
}


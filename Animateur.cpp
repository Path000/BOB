#include "Animateur.h"

Animateur::Animateur() {
  _danse1 = Danse1();
}

void Animateur::setServos(MyServo* servos) {
  _servos = servos;
}

void Animateur::resetAnimationSteps() {
  _servos[SERVO_PIED_GAUCHE].resetAnimationStep();
  _servos[SERVO_PIED_DROIT].resetAnimationStep();
  _servos[SERVO_HANCHE_GAUCHE].resetAnimationStep();
  _servos[SERVO_HANCHE_DROITE].resetAnimationStep();
}

void Animateur::setDanseCourante(byte danseCourante) {
  _danseCourante = danseCourante; //_danses[danseCourante];
  switch(_danseCourante) {
    case 0 :
      return _danse1.init();
    //case 1 :
      //return _danse2.init();
    //case 2 :
      //return _danse3.init();
  }
  return _danse1.init();
}

/*
 * Fonction d'adaptation des tableaux de pas de danse.
 * Retourne la course du pas de danse courante, pour la danse courante et pour le servo donné.
 */
Step Animateur::getStepDeLaDanseCourante(byte servo) {
  switch(_danseCourante) {
    case 0 :
      return _danse1.getCurrentStep(servo);
    //case 1 :
      //return _danse2.getCurrentStep(servo);
    //case 2 :
      //return _danse3.getCurrentStep(servo);
  }
  return _danse1.getCurrentStep(servo);
}

boolean Animateur::danseCourantNextStep() {
  switch(_danseCourante) {
    case 0 :
      return _danse1.nextStep();
    //case 1 :
      //return _danse2.nextStep();
    //case 2 :
      //return _danse3.nextStep();
  }
  return _danse1.nextStep();
}



/**
 * retourne true si danse fini
 */
boolean Animateur::executeDanse() {
  Step stepCourantePG, stepCourantePD, stepCouranteHG, stepCouranteHD;
  switch(_danseCourante) {
    case 0 :
      stepCourantePG = _danse1.getCurrentStep(SERVO_PIED_GAUCHE);
      stepCourantePD = _danse1.getCurrentStep(SERVO_PIED_DROIT);
      stepCouranteHG = _danse1.getCurrentStep(SERVO_HANCHE_GAUCHE);
      stepCouranteHD = _danse1.getCurrentStep(SERVO_HANCHE_DROITE);
      break;
    //case 1 :
      //stepCourantePG = _danse2.getCurrentStep(SERVO_PIED_GAUCHE);
      //stepCourantePD = _danse2.getCurrentStep(SERVO_PIED_DROIT);
      //stepCouranteHG = _danse2.getCurrentStep(SERVO_HANCHE_GAUCHE);
      //stepCouranteHD = _danse2.getCurrentStep(SERVO_HANCHE_DROITE);
      //break;
    //case 2 :
      //stepCourantePG = _danse3.getCurrentStep(SERVO_PIED_GAUCHE);
      //stepCourantePD = _danse3.getCurrentStep(SERVO_PIED_DROIT);
      //stepCouranteHG = _danse3.getCurrentStep(SERVO_HANCHE_GAUCHE);
      //stepCouranteHD = _danse3.getCurrentStep(SERVO_HANCHE_DROITE);
      //break;
  }
  
  boolean finiPG = _servos[SERVO_PIED_GAUCHE].animateStep(stepCourantePG.angleFin, stepCourantePG.duree);
  boolean finiPD = _servos[SERVO_PIED_DROIT].animateStep(stepCourantePD.angleFin, stepCourantePD.duree);
  boolean finiHG = _servos[SERVO_HANCHE_GAUCHE].animateStep(stepCouranteHG.angleFin, stepCouranteHG.duree);
  boolean finiHD = _servos[SERVO_HANCHE_DROITE].animateStep(stepCouranteHD.angleFin, stepCouranteHD.duree);

  // Chaque pas est synchronisé.
  if(finiHG && finiHD && finiPG && finiPD) {
    resetAnimationSteps();
    if(!danseCourantNextStep()) {
      return true;
    }
  }
  return false;
}


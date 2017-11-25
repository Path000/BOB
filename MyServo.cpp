#include "MyServo.h"

MyServo::MyServo(byte pin, byte min, byte mid, byte max) {
  _pin = pin;
  _min = min;
  _mid = mid;
  _max = max;
}

void MyServo::setup() {
  _servo.attach(_pin);
  resetAnimationStep();
  write(_mid);
}

void MyServo::write(long pos) {
  // On défini les bornes
  if(_max > _min) {
    if(pos > _max) pos = _max;
  }
  else {
    if(pos < _min) pos = _min;
  }
  
  _servo.write(pos);
}

/**
 * Appelé par l'animateur à la fin de chaque step
 * après sync des 4 servos.
 */
void MyServo::resetAnimationStep() {
  _animationEnded = false;
  _animationStartTimestamp = 0;
}

/**
 * retourne true si course finie
 */
boolean MyServo::animateStep(byte angleFin, unsigned long duree) {
  // On fait rien si la course est déjà finie.
  if(_animationEnded) {
    return true;
  }
 
  // Si la durée est 0, on fait juste un servo.write
  if(duree == 0 || _angleDebut == angleFin) {
    write(angleFin);
    _animationEnded = true;
    return true;
  }

  // on conserve l'heure de démarrage de l'animation
  if(_animationStartTimestamp == 0) {
    _animationStartTimestamp = millis();
  }

  unsigned long timePosition = millis() - _animationStartTimestamp;
  // On map la position angulaire sur la durée de la course.
  long angle = map(timePosition, 0, duree, _angleDebut, angleFin);

  // On défini les bornes
  if(angleFin > _angleDebut) {
    if(angle > angleFin) angle = angleFin;
  }
  else {
    if(angle < angleFin) angle = angleFin;
  }
  
  write(angle);
  
  if(angle == angleFin) {
    // On conserve l'angle pour la prochaine animation
    _angleDebut = angleFin;
    _animationEnded = true;
    return true;
  }
  return false;
}


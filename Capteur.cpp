#include "Capteur.h"

Capteur::Capteur() {
}

void Capteur::setup(byte pinTrig, byte pinEcho) {
  _pinTrig = pinTrig;
  _pinEcho = pinEcho;
  pinMode(_pinTrig, OUTPUT); 
  digitalWrite(_pinTrig, LOW); 
  pinMode(_pinEcho, INPUT);
}

long Capteur::lectureDistanceCm() {
  digitalWrite(_pinTrig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(_pinTrig, LOW);
  long lecture_echo = pulseIn(_pinEcho, HIGH, 60000); // 60ms
  return(lecture_echo / 58); 
}


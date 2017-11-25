#ifndef StateMachine_h
#define StateMachine_h

#include "Capteur.h"
#include "Animateur.h"
#include "param.h"

#include <Arduino.h>

class StateMachine {
  public:
    StateMachine();
    void setCapteur(Capteur capteur);
    void setAnimateur(Animateur animateur);
    void setup();
    void run();
  private:
    byte decideSiDanse();
    byte choisirDanse();
    byte danse();
    Capteur _capteur;
    Animateur _animateur;
    byte _etat;
};

#endif

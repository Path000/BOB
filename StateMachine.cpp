#include "StateMachine.h"

StateMachine::StateMachine() {
}

void StateMachine::setAnimateur(Animateur animateur) {
  _animateur = animateur;
}

void StateMachine::setup() {
  _capteur.setup(PIN_TRIG, PIN_ECHO);
  // Seed random
  randomSeed(analogRead(0));
  _etat = ETAT_EN_ATTENTE;
}

void StateMachine::run() {
  switch(_etat) {
    case ETAT_EN_ATTENTE :
      _etat = decideSiDanse();
      break;
    case ETAT_CHOIX_DANSE :
      _etat = choisirDanse();
      break;
    case ETAT_DANSE :
      _etat = danse();
      break;
  }
}

/**
 * Etat : en attente
 * retourne l'état  en attente ou choix danse
 */
byte StateMachine::decideSiDanse() {
  long distanceCm = _capteur.lectureDistanceCm();
  if(distanceCm <= 10 || distanceCm >= 100) {  
    //_animateur.positionInitiale();
    delay(500);
    return ETAT_EN_ATTENTE;
  }
  return ETAT_CHOIX_DANSE;
}

/**
 * Etat : choix danse
 * retourne l'état danse
 */
byte StateMachine::choisirDanse() {
  byte danseCourante = random(MAX_DANSES);
  _animateur.setDanseCourante(danseCourante);
  return ETAT_DANSE;
}

/**
 * Etat : danse
 * retourne etat En attente ou danse
 */
byte StateMachine::danse() {
  boolean termine = _animateur.executeDanse();
  if(termine) {
    delay(50);
    return ETAT_EN_ATTENTE;
  }
  return ETAT_DANSE;
}


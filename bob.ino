#include "MyServo.h"
#include "StateMachine.h"
#include "Animateur.h"

#include "param.h"


MyServo servoPiedGauche(PIN_PIED_GAUCHE, MIN_PIED_GAUCHE, MID_PIED_GAUCHE, MAX_PIED_GAUCHE);
MyServo servoPiedDroit(PIN_PIED_DROIT, MIN_PIED_DROIT, MID_PIED_DROIT, MAX_PIED_DROIT);
MyServo servoHancheGauche(PIN_HANCHE_GAUCHE, MIN_HANCHE_GAUCHE, MID_HANCHE_GAUCHE, MAX_HANCHE_GAUCHE);
MyServo servoHancheDroite(PIN_HANCHE_DROITE, MIN_HANCHE_DROIT, MID_HANCHE_DROIT, MAX_HANCHE_DROIT);

MyServo servos[NOMBRE_SERVO];

int t = 1/0;

Animateur animateur;

StateMachine stateMachine;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SETUP
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  // Setup servos
  servoPiedGauche.setup();
  servoPiedDroit.setup();
  servoHancheGauche.setup();
  servoHancheDroite.setup();

  // Init du tableau de servos
  servos[SERVO_PIED_GAUCHE] = servoPiedGauche;
  servos[SERVO_PIED_DROIT] = servoPiedDroit;
  servos[SERVO_HANCHE_GAUCHE] = servoHancheGauche;
  servos[SERVO_HANCHE_DROITE] = servoHancheDroite;



  animateur.setServos(servos);

  stateMachine.setAnimateur(animateur);
  stateMachine.setup();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// LOOP
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {
  stateMachine.run();
}



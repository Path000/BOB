#ifndef Animateur_h
#define Animateur_h

#include <Arduino.h>
#include "MyServo.h"
#include "Danse1.h"
//#include "Danse2.h"
//#include "Danse3.h"
#include "param.h"

class Animateur
{
  public:
    Animateur();
    void setServos(MyServo* servos);
    boolean executeDanse();
    void setDanseCourante(byte danseCourante);
  private:
    void resetStep();
    MyServo* _servos;
    byte _danseCourante;
    Step getStepDeLaDanseCourante(byte servo);
    boolean danseCourantNextStep();
    void resetAnimationSteps();
    Danse1 _danse1;
  protected:
};

#endif

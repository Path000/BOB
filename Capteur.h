#ifndef Capteur_h
#define Capteur_h

#include <Arduino.h>

class Capteur {
  public:
    Capteur();
    void setup(byte pinTrig, byte pinEcho);
    long lectureDistanceCm();
  private:
    byte _pinTrig;
    byte _pinEcho;
};

#endif

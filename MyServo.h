#ifndef MyServo_h
#define MyServo_h

#include <Arduino.h>
#include <Servo.h>

class MyServo {
  public:
    inline MyServo() {};
    MyServo(byte pin, byte min, byte mid, byte max);
    void setup();
    void write(long pos);
    boolean animateStep(byte angleFin, unsigned long duree);
    void resetAnimationStep();
  private:
    byte _pin;
    byte _min;
    byte _mid;
    byte _max;
    Servo _servo;
    boolean _animationEnded;
    unsigned long _animationStartTimestamp;
    byte _angleDebut;
};

#endif

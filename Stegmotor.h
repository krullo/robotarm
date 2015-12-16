#ifndef Stegmotor_h
#define Stegmotor_h
#include "Arduino.h"

class Stegmotor
{
    public:
        Stegmotor(int, int, int, int, int, int);
        void turn(float);
        void endposition(float);
    
    private:
        int pwr_a;
        int pwr_b;
        int dir_a;
        int dir_b;
        int endup;
        int enddown;
        float degreetarget;
        float forward(float);
        float backward(float);
        float degreeposs;
        
};
#endif
    

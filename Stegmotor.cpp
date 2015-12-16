#include "Arduino.h"
#include "Stegmotor.h"

Stegmotor::Stegmotor(int pa, int pb, int da, int db, int eu, int ed)
{
    pwr_a = pa;
    pwr_b = pb;
    dir_a = da;
    dir_b = db;
    endup = eu;
    enddown = ed;
    pinMode(pwr_a,OUTPUT);
    pinMode(pwr_b,OUTPUT);
    pinMode(dir_a,OUTPUT);
    pinMode(dir_b,OUTPUT);
    pinMode(endup, INPUT);
    pinMode(enddown, INPUT);
  
}

void Stegmotor::endposition(float endposs){
    degreeposs=endposs;
}

void Stegmotor::turn(float degreetarget)
{
  if( degreetarget > degreeposs )
  {
    degreeposs = forward(degreetarget);
  } 
  else 
  {
    degreeposs = backward(degreetarget);
  }  
}
float Stegmotor::forward(float degreetarget)
{
    int stegtid = 30;
    int poss = 1;
  while(degreeposs<=degreetarget){
    if (poss == 4 && degreeposs<=degreetarget)
    {
    poss=1;
    digitalWrite(pwr_a,HIGH);
    digitalWrite(pwr_b,LOW);
    digitalWrite(dir_a,HIGH);
    digitalWrite(dir_b,LOW);
    degreeposs = degreeposs+1.8 ;
    delay(stegtid) ; 
        if(digitalRead(enddown)){
            break;
    }
    }
    else if (poss==1 && degreeposs<=degreetarget)
    {
    poss=2;
    digitalWrite(pwr_a,LOW);
    digitalWrite(pwr_b,HIGH);
    digitalWrite(dir_a,LOW);
    digitalWrite(dir_b,HIGH);
    degreeposs=degreeposs+1.8;
    delay(stegtid);
        if(digitalRead(enddown)){
            break;
    }
    }
    else if (poss==2 && degreeposs<=degreetarget)
    {
    poss=3;
    digitalWrite(pwr_a,HIGH);
    digitalWrite(pwr_b,LOW);
    digitalWrite(dir_a,LOW);
    digitalWrite(dir_b,LOW);
    degreeposs=degreeposs+1.8;
    delay(stegtid);
        if(digitalRead(enddown)){
            break;
    }
    }
    else if (poss=3 && degreeposs<=degreetarget)
    {
    poss=4;
    digitalWrite(pwr_a,LOW);
    digitalWrite(pwr_b,HIGH);
    digitalWrite(dir_a,LOW);
    digitalWrite(dir_b,LOW);
    degreeposs=degreeposs+1.8;
    delay(stegtid);
        if(digitalRead(enddown)){
            break;
    }
    }
    
  }
  degreeposs = degreetarget;
  return degreeposs;
  
}

float Stegmotor::backward(float degreetarget)
{
    int stegtid = 30;
    int poss = 1;
  while(degreeposs>=degreetarget)
  {
    if (poss==1 && degreeposs>=degreetarget)
    {
      poss=4;
      digitalWrite(pwr_a,LOW);
      digitalWrite(pwr_b,HIGH);
      digitalWrite(dir_a,LOW);
      digitalWrite(dir_b,LOW);
      degreeposs=degreeposs-1.8;
      delay(stegtid);
        if(digitalRead(endup)){
            break;
    }
    }
    else if (poss==4 && degreeposs>=degreetarget)
    {
      poss=3;
      digitalWrite(pwr_a,HIGH);
      digitalWrite(pwr_b,LOW);
      digitalWrite(dir_a,LOW);
      digitalWrite(dir_b,LOW);
      degreeposs=degreeposs-1.8;
      delay(stegtid);
        if(digitalRead(endup)){
            break;
    }
    }
    else if (poss==3 && degreeposs>=degreetarget)
    {
      poss=2;
      digitalWrite(pwr_a,LOW);
      digitalWrite(pwr_b,HIGH);
      digitalWrite(dir_a,LOW);
      digitalWrite(dir_b,HIGH);
      degreeposs=degreeposs-1.8;
      delay(stegtid);
        if(digitalRead(endup)){
            break;
    }
    }
    else if (poss==2 && degreeposs>=degreetarget)
    {
      poss=1;
      digitalWrite(pwr_a,HIGH);
      digitalWrite(pwr_b,LOW);
      digitalWrite(dir_a,HIGH);
      digitalWrite(dir_b,LOW);
      degreeposs=degreeposs-1.8;
      delay(stegtid);
        if(digitalRead(endup)){
            break;
    }
    }
  }
  degreeposs = degreetarget;
  return degreeposs;
    
}

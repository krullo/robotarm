    #include <math.h>


const int pwr_a = 3;
const int pwr_b = 9;
const int dir_a = 2;
const int dir_b = 8;

int stegtid = 10;
float degreesPerStep = 7.2;

void setup() {
  // put your setup code here, to run once:
 
  pinMode(pwr_a,OUTPUT);
  pinMode(pwr_b,OUTPUT);
  pinMode(dir_a,OUTPUT);
  pinMode(dir_b,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  turn(187.1);
  delay(1000);
  turn(-180);
  delay(2000);
}

void turn(float degree){
  if( degree > 0 ){
    int steps = (int)(degree / degreesPerStep + 0.5);
    forward(steps);
  } else {
    int steps = (int)(-degree / degreesPerStep + 0.5);
    backward(steps);
  }
}

void forward(int varv){
  for(int i = 0; i< varv; i++){
    delay(stegtid);
    digitalWrite(pwr_a,HIGH);
    digitalWrite(pwr_b,LOW);
    digitalWrite(dir_a,HIGH);
    digitalWrite(dir_b,LOW);
    delay(stegtid) ; 
    digitalWrite(pwr_a,LOW);
    digitalWrite(pwr_b,HIGH);
    digitalWrite(dir_a,LOW);
    digitalWrite(dir_b,HIGH);
    delay(stegtid);
    digitalWrite(pwr_a,HIGH);
    digitalWrite(pwr_b,LOW);
    digitalWrite(dir_a,LOW);
    digitalWrite(dir_b,LOW);
    delay(stegtid);
    digitalWrite(pwr_a,LOW);
    digitalWrite(pwr_b,HIGH);
    digitalWrite(dir_a,LOW);
    digitalWrite(dir_b,LOW);
  }
  //RESET MOTOR
  delay(stegtid);
  digitalWrite(pwr_a,LOW);
  digitalWrite(pwr_b,LOW);
  digitalWrite(dir_a,LOW);
  digitalWrite(dir_b,LOW);
}
void backward(int varv){
  for(int i = 0; i< varv; i++){
    delay(stegtid);
    digitalWrite(pwr_a,LOW);
    digitalWrite(pwr_b,HIGH);
    digitalWrite(dir_a,LOW);
    digitalWrite(dir_b,LOW);
    delay(stegtid);
    digitalWrite(pwr_a,HIGH);
    digitalWrite(pwr_b,LOW);
    digitalWrite(dir_a,LOW);
    digitalWrite(dir_b,LOW);
    delay(stegtid);
    digitalWrite(pwr_a,LOW);
    digitalWrite(pwr_b,HIGH);
    digitalWrite(dir_a,LOW);
    digitalWrite(dir_b,HIGH);
    delay(stegtid);
    digitalWrite(pwr_a,HIGH);
    digitalWrite(pwr_b,LOW);
    digitalWrite(dir_a,HIGH);
    digitalWrite(dir_b,LOW);
  }
  //RESET MOTOR
  delay(stegtid);
  digitalWrite(pwr_a,LOW);
  digitalWrite(pwr_b,LOW);
  digitalWrite(dir_a,LOW);
  digitalWrite(dir_b,LOW);
}


#include <IRremote.h>


 
const int RECV_PIN_CENTER=11;
const int RECV_PIN_LEFT =12;
const int RECV_PIN_RIGHT=10;

//const int echo

static long dis=0;

const int motorA_dir=8;
const int motorA_spd=9;
const int motorB_dir=4;
const int motorB_spd=5;

IRrecv irrecv_left(RECV_PIN_LEFT);
IRrecv irrecv_center(RECV_PIN_CENTER);
IRrecv irrecv_right(RECV_PIN_RIGHT);

//long get_distance();
 
void motor_go(const int &);
void motor_left(const int &);
void motor_left2(const int &);
void motor_right(const int &);
void motor_right2(const int &);
void motor_stop();

 

void setup()

{
  //pinMode(trig,OUTPUT);
  //pinMode(echo,INPUT);
  
  Serial.begin(9600);

  pinMode(RECV_PIN_LEFT,INPUT);

  pinMode(RECV_PIN_RIGHT,INPUT);

  pinMode(RECV_PIN_CENTER,INPUT);

 

}

 

void loop()

{
  
  
  int val_left=digitalRead(RECV_PIN_LEFT);

 

  int val_right=digitalRead(RECV_PIN_RIGHT);

  int val_center=digitalRead(RECV_PIN_CENTER); 
  //dis=get_distance();
  
  if(!val_center&&val_right&&val_left)
  {
    //if(dis>=30)
    //{
      Serial.println("center");
      motor_go(150);
    delay(1000);
    //}  
}
  
  else if(!val_left&&!val_center)

  {
    motor_left2(150);
    delay(1000);
  }

  else if(!val_left&&val_center)

  {
   motor_left(150);
   delay(1000);
  }else if(!val_right&&!val_center)
  {
    motor_right(150);
    delay(1000);
  }
  else if(!val_right&&val_center)
  {
    motor_right2(150);
    delay(1000);
  }
  else{
    //if(dir<30)
    motor_stop();
  }
  irrecv_left.resume();

  irrecv_right.resume();
  irrecv_center.resume();
  
  delay(100);

}

  
void motor_go(const int & spd)
{
  digitalWrite(motorA_dir,HIGH);
  digitalWrite(motorB_dir,LOW);
  analogWrite(motorA_spd,spd);
  analogWrite(motorB_spd,spd);
}

void motor_left(const int & spd)
{
  analogWrite(motorA_spd,spd);
  analogWrite(motorB_spd,spd-70);
  
}

void motor_right(const int & spd)
{
  analogWrite(motorA_spd,spd-70);
  analogWrite(motorB_spd,spd);
}

void motor_stop()
{
  analogWrite(motorA_spd,0);
  analogWrite(motorB_spd,0);
}

void motor_left2(const int & spd)
{
  analogWrite(motorA_spd,spd);
  analogWrite(motorB_spd,spd-100);
}

void motor_right2(const int & spd)
{
  analogWrite(motorB_spd,spd);
  analogWrite(motorA_spd,spd-100);
}

/*double get_distance()
{
  digitalWrite(tirg,LOW);
  delayMicroseconds(2);
  digitalWrite(tirg,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  long duration=pulseIn(echo,HIGH);
  
  long distance=(duration *340)/2/10000;
  
  return distance;
}*/

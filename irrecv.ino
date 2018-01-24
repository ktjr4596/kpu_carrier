#include <IRremote.h>

#define LEDLEFT 3

#define LEDRIGHT 4
//0124
 

int RECV_PIN_LEFT = 5;

int RECV_PIN_RIGHT=6;

IRrecv irrecv_left(RECV_PIN_LEFT);

IRrecv irrecv_right(RECV_PIN_RIGHT);

 

 

void setup()

{

  pinMode(LEDLEFT,OUTPUT);

  pinMode(LEDRIGHT,OUTPUT);

   Serial.begin(9600);

  pinMode(RECV_PIN_LEFT,INPUT);

  pinMode(RECV_PIN_RIGHT,INPUT);

  

 

  irrecv_left.enableIRIn(); // Start the receiver

  irrecv_right.enableIRIn();

 

}

 

void loop()

{

  int val_left=digitalRead(RECV_PIN_LEFT);

 

  int val_right=digitalRead(RECV_PIN_RIGHT);

  

  if(val_left==LOW)

  {

    digitalWrite(LEDLEFT,HIGH);

    delay(100);

    digitalWrite(LEDLEFT,LOW);

    delay(100);

  }

  if(val_right==LOW)

  {

    digitalWrite(LEDRIGHT,HIGH);

    delay(100);

    digitalWrite(LEDRIGHT,LOW);

    delay(100);

  }

  irrecv_left.resume();

  irrecv_right.resume();

  delay(100);

}

 //01.23
#include <IRremote.h>

#define motor_b_spd 3
#define motor_b_dir1 4
#define motor_b_dir2 5
#define motor_a_dir1 7
#define motor_a_dir2 8
#define motor_a_spd 9


//int trig=12;
//int echo=13;

void setmotor_a_go();
void setmotor_b_go();

//int RECV_PIN_LEFT = 5;

int RECV_PIN_RIGHT=11;

//IRrecv irrecv_left(RECV_PIN_LEFT);

IRrecv irrecv_right(RECV_PIN_RIGHT);

 

 

void setup()

{

   Serial.begin(9600);

//  pinMode(RECV_PIN_LEFT,INPUT);

  pinMode(RECV_PIN_RIGHT,INPUT);

  

   pinMode(motor_a_dir1,OUTPUT);
   pinMode(motor_a_dir2,OUTPUT);
   pinMode(motor_b_dir1,OUTPUT);
   pinMode(motor_b_dir2,OUTPUT);
   
   //pinMode(trig,OUTPUT);
   //pinMode(echo,INPUT);
   //irrecv_left.enableIRIn(); // Start the receiver

  irrecv_right.enableIRIn();

 

}

 

void loop()

{
  
  /*digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  long duration=pulseIn(echo,HIGH);
  long distance=(duration*340)/2/10000;
  
  Serial.print(distance);
  Serial.println("cm");
  delay(300);
  */
  int val_right=digitalRead(RECV_PIN_RIGHT);
  

    Serial.println("go");
    setmotor_a_go();
    setmotor_b_go();
    analogWrite(motor_a_spd,200);
    
 
    analogWrite(motor_b_spd,200);
    irrecv_right.resume();
    delay(1000);
  
 /* else if(val_right==HIGH)
  {
    Serial.println("stop");
    digitalWrite(motor_a_dir1,LOW);
    digitalWrite(motor_a_dir2,LOW);
    
    digitalWrite(motor_b_dir1,LOW);
    digitalWrite(motor_b_dir2,HIGH);
    analogWrite(motor_b_spd,200);
    irrecv_right.resume();
    delay(1000);
  }*/
  
  //int val_left=digitalRead(RECV_PIN_LEFT);

 

  

  

  /*if(val_left==LOW)

  {

    digitalWrite(LEDLEFT,HIGH);

    delay(100);

    digitalWrite(LEDLEFT,LOW);

    delay(100);

  }*/


  //irrecv_left.resume();

  

  delay(100);

}


void setmotor_a_go()
{
    digitalWrite(motor_a_dir1,HIGH);
    digitalWrite(motor_a_dir2,LOW);
}
void setmotor_b_go()
{
  digitalWrite(motor_b_dir1,LOW);
  digitalWrite(motor_b_dir2,HIGH);
}

//01.24


 
#include <IRremote.h>

#define motor_b_spd 3
#define motor_b_dir1 4
#define motor_b_dir2 5
#define motor_a_dir1 7
#define motor_a_dir2 8
#define motor_a_spd 9


int trig=12;
int echo=13;

void setmotor_a_go();
void setmotor_b_go();

int RECV_PIN_RIGHT=10;
int RECV_PIN_LEFT=11;

IRrecv irrecv_left(RECV_PIN_LEFT);

IRrecv irrecv_right(RECV_PIN_RIGHT);

 

 

void setup()

{

   Serial.begin(9600);

  pinMode(RECV_PIN_RIGHT,INPUT);
  pinMode(RECV_PIN_LEFT,INPUT);
  

   pinMode(motor_a_dir1,OUTPUT);
   pinMode(motor_a_dir2,OUTPUT);
   pinMode(motor_b_dir1,OUTPUT);
   pinMode(motor_b_dir2,OUTPUT);
   
   pinMode(trig,OUTPUT);
   pinMode(echo,INPUT);
   //irrecv_left.enableIRIn(); // Start the receiver

  //irrecv_right.enableIRIn();


}

 

void loop()

{
  irrecv_left.resume();
  irrecv_right.resume();
  
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  long duration=pulseIn(echo,HIGH);
  long distance=(duration*340)/2/10000;
  
  Serial.print(distance);
  Serial.println("cm");
  delay(300);
  
  int val_right=digitalRead(RECV_PIN_RIGHT);
  int val_left=digitalRead(RECV_PIN_LEFT);
  Serial.print(distance);
  Serial.println("cm");
  
  if(!val_right)
  {
    Serial.println("right");
    setmotor_a_go();
    setmotor_b_go();
    analogWrite(motor_a_spd,200);
    
 
    analogWrite(motor_b_spd,200);
    delay(3000);
  }
  else if(!val_left){
    Serial.println("left");
    setmotor_a_go();
    analogWrite(motor_a_spd,200);
    setmotor_b_stop();
    delay(3000);
    
  }
    /* else if(val_right==HIGH)
  {
    Serial.println("stop");
    digitalWrite(motor_a_dir1,LOW);
    digitalWrite(motor_a_dir2,LOW);
    
    digitalWrite(motor_b_dir1,LOW);
    digitalWrite(motor_b_dir2,HIGH);
    analogWrite(motor_b_spd,200);
    irrecv_right.resume();
    delay(1000);
  }*/
  
  //int val_left=digitalRead(RECV_PIN_LEFT);

 else{
   Serial.println("nono");
   setmotor_a_stop();
    setmotor_b_stop();
 }

  

  

  /*if(val_left==LOW)
  {
    digitalWrite(LEDLEFT,HIGH);
    delay(100);
    digitalWrite(LEDLEFT,LOW);
    delay(100);
  }*/


  //irrecv_left.resume();

  

  delay(100);
}


void setmotor_a_go()
{
    digitalWrite(motor_a_dir1,HIGH);
    digitalWrite(motor_a_dir2,LOW);
}
void setmotor_b_go()
{
  digitalWrite(motor_b_dir1,HIGH);
  digitalWrite(motor_b_dir2,LOW);
}


void setmotor_a_stop()
{
    digitalWrite(motor_a_dir1,LOW);
    digitalWrite(motor_a_dir2,LOW);
}
void setmotor_b_stop()
{
  digitalWrite(motor_b_dir1,LOW);
  digitalWrite(motor_b_dir2,LOW);
}

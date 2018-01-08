#include <IRremote.h>

#define LEDLEFT 3

#define LEDRIGHT 4

 

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

  

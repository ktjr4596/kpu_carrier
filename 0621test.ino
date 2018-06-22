#include <IRremote.h>
#include <Servo.h>
#include<SoftwareSerial.h>

// 마주봤을때 기준 오른쪽 부터 
const int right_max = 4; 
const int right_min = 9; 
const int go = 6;
const int left_min = 7; 
const int left_max = 12; 

//오른쪽바퀴
const int right_speed = 11;
const int right_dir = 10;

//좌측바퀴
const int left_dir = 8;
const int left_speed = 5;

//초음파
const int trig=A3;
const int echo=A2;

//부저
const int buz=A0;
int cm;

Servo sv;
SoftwareSerial bt(2,3); //블루투스 통신

IRrecv ir_left1(left_max);
IRrecv ir_left2(left_min);
IRrecv ir_right1(right_max);
IRrecv ir_right2(right_min);
IRrecv ir_center(go);

void irSetting();

void setup() {
  Serial.begin(9600);
  
  pinMode(right_max,INPUT);
  pinMode(left_speed,INPUT);
  pinMode(go,INPUT);
  pinMode(left_max,INPUT);
  pinMode(left_min,INPUT);
  pinMode(right_min,INPUT);
  pinMode(right_dir,OUTPUT);
  pinMode(left_dir,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buz,OUTPUT);
  
  sv.attach(13); //잠금장치
  
  bt.begin(9600);
  sv.write(0);
  
}

void loop() {
  irSetting();
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  cm = pulseIn(echo, HIGH) / 58;
  Serial.print(cm);
  Serial.println("cm");

  //블루투스 통신
  while(bt.available()){
     byte data=bt.read();
     Serial.println(data);
     if(data==50) // 아스키코드 2일때 잠금
     {
        sv.write(45);
        Serial.println("45");
         delay(100);
     }else if(data==51) //아스키코드 3일때 열림
     {
       sv.write(130);
       Serial.println("130");
       delay(100);
     }
     else if(data==52) //아스키코드 4일때 1.5미터 초과로 울림 및 정지
     {
      digitalWrite(buz,HIGH);
      Serial.println("buz on");
      analogWrite(left_speed,0);
      analogWrite(right_speed,0);
      
     }
     else if(data==53) //아스키코드 5일때 1.5미터 이하로 소리끔
     {
      digitalWrite(buz,LOW);
      Serial.println("buz off");
     }
   }

  //초음파 30cm이하일때 멈춤
 if(cm<30){
     digitalWrite(left_dir,LOW);
    digitalWrite(right_dir,HIGH);
    analogWrite(left_speed,0);
    analogWrite(right_speed,0);
    delay(1000);
  }

  //적외선 
else if(!digitalRead(right_min))
  {
    Serial.println("right_min");
    digitalWrite(left_dir,LOW);
    digitalWrite(right_dir,HIGH);
    analogWrite(left_speed,100);
    analogWrite(right_speed,255);
    delay(300);
    }
  
else if(!digitalRead(go))
  {
    Serial.println("go");
    digitalWrite(left_dir,LOW);
    digitalWrite(right_dir,HIGH);  
    analogWrite(left_speed,255);
    analogWrite(right_speed,255);
     delay(300);
  }
else if(!digitalRead(left_min))
  {
    Serial.println("left_min");
    digitalWrite(left_dir,LOW);
    digitalWrite(right_dir,HIGH);
    analogWrite(left_speed,255);
    analogWrite(right_speed,100);
     delay(300);
  }
else if(!digitalRead(left_max))
  {
    Serial.println("left_max");
    digitalWrite(left_dir,LOW);
    digitalWrite(right_dir,HIGH);
    analogWrite(left_speed,255);
    analogWrite(right_speed,0);
     delay(300);
  }
 else if(!digitalRead(right_max))
  {
    Serial.println("right_max");
    digitalWrite(left_dir,LOW);
    digitalWrite(right_dir,HIGH);
    analogWrite(left_speed,0);
    analogWrite(right_speed,255);
     delay(300);
  }
}
  
void irSetting(){
ir_left1.resume();
ir_left2.resume();
ir_right1.resume();
ir_right2.resume();
ir_center.resume();
}

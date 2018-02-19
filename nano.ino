#include <SoftwareSerial.h>

 

SoftwareSerial BTSerial(2, 3); // SoftwareSerial(TX, RX)
SoftwareSerial BTSerial2(4,5);

String readData;
int num1=55,num2,num3;


void setup()

{

Serial.begin(9600);
Serial.println("Hello!");

 

// set the data rate for the BT port

BTSerial.begin(9600);

BTSerial2.begin(9600);
}

void loop(){
sendATcommnadToiBeacon("AT-DISI?",800);
compareBeacon(num1,num2,num3);
}

void sendATcommnadToiBeacon(const char *toSend,unsigned long milliseconds){
  String result = "";
  unsigned long startTime = millis();
  
  BTSerial.print(toSend);
  BTSerial.listen();
  while(millis()-startTime<milliseconds){
    while(BTSerial.available()){
      char c = BTSerial.read();
      result+=c;
    }
  }
  Serial.println();
  readData=result;
    if(readData.indexOf("D43639C465A6")>-1){
    String RSSIVal="";
    int num=0;
    num=readData.indexOf("D43639C465A6");
    for(int i=readData.indexOf("D43639C465A6")+15;i<readData.indexOf("D43639C465A6")+18;i++){
      RSSIVal+=readData.charAt(i);
    }
    if(RSSIVal.toInt()!=0) 
    {
      num1=RSSIVal.toInt();
      Serial.print(RSSIVal.toInt());
    }
    
  }
  else if(readData.indexOf("D43639C46FEE")>-1){
    String RSSIVal="";
    int num=0;
    num=readData.indexOf("D43639C46FEE");
    for(int i=readData.indexOf("D43639C46FEE")+15;i<readData.indexOf("D43639C46FEE")+18;i++){
      RSSIVal+=readData.charAt(i);
    }
    if(RSSIVal.toInt()!=0) 
    {
      num2=RSSIVal.toInt();
      Serial.print(RSSIVal.toInt());
    }
    
  }
  
  else if(readData.indexOf("D43639C47120")>-1){
    String RSSIVal="";
    int num=0;
    num=readData.indexOf("D43639C47120");
    for(int i=readData.indexOf("D43639C47120")+15;i<readData.indexOf("D43639C47120")+18;i++){
      RSSIVal+=readData.charAt(i);
    }
    if(RSSIVal.toInt()!=0) 
    {
      num3=RSSIVal.toInt();
      Serial.print(RSSIVal.toInt());
    }
  }
  readData="";
}

void compareBeacon(int num1,int num2, int num3)
{
  char result=1;
  if((num2<num1)&&(num2<num3)){
     Serial.print("-----num1 : ");
    Serial.print(num1);
      Serial.print(", num2 : ");
    Serial.print(num2);
      Serial.print(",num3 : ");
    Serial.print(num3);
    Serial.println("---------");
    Serial.println("2번 비콘이 가장 강력");
    BTSerial2.print('2');
  }
  else if((num3<num1)&&(num3<num2)){
     Serial.print("-----num1 : ");
    Serial.print(num1);
      Serial.print(", num2 : ");
    Serial.print(num2);
      Serial.print(",num3 : ");
    Serial.print(num3);
    Serial.println("---------");
    Serial.println("3번 비콘이 가장 강력");
    BTSerial2.print('3');
  }
 
  /*
  else {
    Serial.print("-----num1 : ");
    Serial.print(num1);
      Serial.print(", num2 : ");
    Serial.print(num2);
      Serial.print(",num3 : ");
    Serial.print(num3);
    Serial.println("---------");
    
    Serial.println("그냥 전진");
  }
  */
    
}


#include <SoftwareSerial.h> //Serial 통신을 위한 헤더파일

#define BE1 "D43639C465A6" //1번 비콘의 MAC 주소
#define BE2 "D43639C46FEE" //2번 비콘의 MAC 주소
#define BE3 "D43639C47120" //3번 비콘의 MAC 주소

SoftwareSerial BTSerial(2, 3); // SoftwareSerial(TX, RX) 비콘검색을 위한 HM-10 모듈
SoftwareSerial BTSerial2(4,5); // SoftwareSerial(TX, RX) 블루투스 통신을 위한 HC-06 모듈

String readData; //임시 String
int num1,num2,num3; // 각 비콘의 RSSI 크기 저장

void researchBeacon(const char, unsigned long); //비콘을 검색하는 기능 함수(명령어,시간초)
void compareBeacon(int,int,int); //비콘의 세기 비교하여 큰 값을 측정하는 함수(비콘명1,비콘명2,비콘명3)

void setup()
{
  Serial.begin(9600); // Serial 통신
  Serial.println("Hello!");

  pinMode(7,OUTPUT); // 적외선 송신 핀
  
  BTSerial.begin(9600); // HM-10 블루투스 통신
  BTSerial2.begin(9600); //HC-06 블루투스 통신
}

void loop(){
  digitalWrite(7,HIGH); //적외선 송신
  researchBeacon("AT-DISI?",1000); // 명령어(비콘검색), 시간초(1초)
  compareBeacon(num1,num2,num3); // 각 비콘의 세기를 비교
}

void researchBeacon(const char *toSend,unsigned long milliseconds){
  String result = ""; //임시 저장 String
  double distance1;
  double distance2;
  double distance3;
  unsigned long startTime = millis(); //아두이노 코드 실행시점으로부터의 경과시간(msec)
  
  BTSerial.print(toSend); //HM-10모듈에 비콘검색 명령
  BTSerial.listen(); //블루투스 모듈중 hm-10모듈을 쓰겠다는 의미
  while(millis()-startTime<milliseconds){ // 경과시간이 < 0.8 일때 마다 명령어 값을 result에 저장
    while(BTSerial.available()){
      char c = BTSerial.read();
      result+=c;
    }
  }
  Serial.println();
  readData=result;
    if(readData.indexOf(BE1)>-1){  //저장된 문자열에 1번 비콘의 MAC주소가 있을 경우
      String RSSIVal="";
      int num=0;
      num=readData.indexOf(BE1);
      for(int i=readData.indexOf(BE1)+15;i<readData.indexOf(BE1)+18;i++){ //String parameter에서 RSSI 부분 가져오기
        RSSIVal+=readData.charAt(i);
      }
      if(RSSIVal.toInt()!=0) 
      {
        num1=RSSIVal.toInt(); //1번 비콘의 RSSI 크기 저장
        distance1 = (16*pow(10,num1/20.0)) /30144.0; // d = (전파 속도 / 4pi 주파수) * 10^(RSSI/20) cf) 전파의속도 : 2Mbps, 주파수 : 2.4GHz

        //시리얼에 보여주기용
        Serial.print(RSSIVal.toInt());
        Serial.print("---------distance1 : ");
        Serial.print(distance1,2); // 소수점 2번째자리까지
        Serial.print("");
      }
  }
  else if(readData.indexOf(BE2)>-1){
    String RSSIVal="";
    int num=0;
    num=readData.indexOf(BE2);
    for(int i=readData.indexOf(BE2)+15;i<readData.indexOf(BE2)+18;i++){
      RSSIVal+=readData.charAt(i);
    }
    if(RSSIVal.toInt()!=0) 
    {
      num2=RSSIVal.toInt();
      distance2 = (16*pow(10,num2/20.0)) /30144.0;
      Serial.print(RSSIVal.toInt());
      Serial.print("------------ distance2 : ");
      Serial.print(distance2,2);
      Serial.println("");
    }
    
  }
  
  else if(readData.indexOf(BE3)>-1){
    String RSSIVal="";
    int num=0;
    num=readData.indexOf(BE3);
    for(int i=readData.indexOf(BE3)+15;i<readData.indexOf(BE3)+18;i++){
      RSSIVal+=readData.charAt(i);
    }
    if(RSSIVal.toInt()!=0) 
    {
      num3=RSSIVal.toInt();
      distance3 = (16*pow(10,num3/20.0)) /30144;
      Serial.print(RSSIVal.toInt());
      Serial.print("------------ distance3 : ");
      Serial.print(distance3,2);
      Serial.println("");
    }
  }
  readData="";
}

void compareBeacon(int num1,int num2, int num3)
{
  char numbeacon;
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
  else if((num1<num2)&&(num1<num3)){
     Serial.print("-----num1 : ");
    Serial.print(num1);
      Serial.print(", num2 : ");
    Serial.print(num2);
      Serial.print(",num3 : ");
    Serial.print(num3);
    Serial.println("---------");
     Serial.println("1번 비콘이 가장 강력");
     BTSerial2.print('1');
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

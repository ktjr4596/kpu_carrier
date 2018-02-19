#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2,3); // SoftwareSerial(RX, TX)
char recv_str[150];

int sendBlueToothCommand(char);
void setup()

{

Serial.begin(9600);

Serial.println("Hello!");

 

// set the data rate for the BT port

bluetooth.begin(9600);

}

void loop(){

while(1){
  sendBlueToothCommand("AT+DISI?");
  delay(1500);

}
}

int sendBlueToothCommand(char command[])
{
  
  Serial.print("send : ");
  Serial.print(command);
  Serial.println("");
  bluetooth.print(command);
  delay(300);
  if(recvMsg(400)!=0)return -1;
  Serial.print("recv: ");
  Serial.print(recv_str);
  Serial.println("");
  
  
  return 0;
}

int recvMsg(unsigned int timeout)
{
  unsigned int time =0;
  unsigned char num;
  unsigned char i;
  i=0;
  while(1){
    delay(100);
    if(bluetooth.available())
    {
      recv_str[i]=char(bluetooth.read());
      i++;
      break;
    }
    time++;
    if(time>(timeout/50))return -1;
    
    }
    while(bluetooth.available()&&(i<100))
    {
      recv_str[i]=char(bluetooth.read());
      i++;
  }
  recv_str[i]='\0';
  return 0;

}


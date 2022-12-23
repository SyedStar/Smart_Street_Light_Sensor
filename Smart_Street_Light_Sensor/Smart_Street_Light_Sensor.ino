#include <SoftwareSerial.h>

int IR1 = 2;
int IR2 = 3;
int IR3 = 4;
int IR4 = 5;
int ldr = 6;
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int input1=1;
int input2=1;
int input3=1;
int input4=1;
int input5=0;

void setup()
{
    Serial.begin(9600);   //Initialise serial to communicate with GSM Modem
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
  pinMode(IR4,INPUT);
  pinMode(ldr,INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void gsm_send()
{
  Serial.println("AT"); //Once the handshake test is successful, it will back to OK
  delay(2000);
  Serial.println("AT+CMGF=1"); // Configuring TEXT mode
  delay(2000);
  Serial.println("AT+CMGS=\"+918296015633\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  delay(2000);
  Serial.println("Street Light ON "); //text content
  delay(2000);
  Serial.println((char)26);
  delay(2000);

  }
 void gsm_send4()
{
  Serial.println("AT"); //Once the handshake test is successful, it will back to OK
  delay(2000);
  Serial.println("AT+CMGF=1"); // Configuring TEXT mode
  delay(2000);
  Serial.println("AT+CMGS=\"+918296015633\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  delay(2000);
  Serial.println("Street Light 5 on for Night"); //text content
  delay(2000);
  Serial.println((char)26);
  delay(2000);

  }




void loop()
{

input1 = digitalRead(IR1);
input2 = digitalRead(IR2);
input3 = digitalRead(IR3);
input4 = digitalRead(IR4);
input5 = digitalRead(ldr);

  
if (input1==0)
  {
 digitalWrite(led1,HIGH);
   }
  else{
     digitalWrite(led1,LOW);
     }
if (input2==0)
  {
 digitalWrite(led2,HIGH);
   }
else{
     digitalWrite(led2,LOW);
 delay(100);
    }
if (input3==0)
  {
 digitalWrite(led3,HIGH);
  }
else
{
 digitalWrite(led3,LOW);
 delay(100);
    }
    if (input4==0)
  {
 digitalWrite(led4,HIGH);
 delay(100);
 Serial.print("Light ON ");
  gsm_send();
  }
  else{
     digitalWrite(led4,LOW);
 delay(100);
    }
    if (input5==1)
  {
 digitalWrite(led5,HIGH);
 delay(100);
 Serial.print("Light 5 on LDR");
 gsm_send4();
  }
  else{
     digitalWrite(led5,LOW);
 delay(100);
    }
}

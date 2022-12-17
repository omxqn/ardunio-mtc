#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Servo.h>

// Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX = 13; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 12; // Connects to module's TX 

int LED1 = 5; // pin 5 LED
int LED2 = 6; // pin 5 LED

SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
# define Acknowledge 0x00
# define ACTIVATED LOW
# define VCC2 10

// Create the Player object
DFRobotDFPlayerMini player;
int sensorValue = 0;
bool alarm_active = false;
bool start = false;
int start_state = 0;
Servo servo;
Servo servo2;
Servo servo3;

void setup() {
  pinMode(VCC2,OUTPUT);
  digitalWrite(VCC2,HIGH);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,INPUT);
  digitalWrite(LED2,HIGH);
  // Init USB serial port for debugging
  Serial.begin(9600);

  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);

  delay(50);
  servo.attach(2);  // attaches the servo on pin 9 to the servo object
  servo.write(180);

  servo2.attach(3);  // attaches the servo on pin 9 to the servo object
  servo2.write(0);
  servo3.attach(4);  // attaches the servo on pin 9 to the servo object
  servo3.write(0);

 
  // Start communication with DFPlayer Mini
  if (player.begin(softwareSerial)) {
    Serial.print(" OK ");

    // Set volume to maximum (0 to 30).
    player.volume(30);

  } else {
    Serial.print("Connecting to DFPlayer Mini failed!");
  }
}



void alarm(){

  Serial.print(" Alarm started! ");
  player.play(2);
  delay(15);
  digitalWrite(LED1,LOW);
  
}

void loop() {
 
  delay(500);
  
  sensorValue = analogRead(0);
  Serial.print(sensorValue);
  Serial.print(" ");
  
  start_state = digitalRead(LED2);
  Serial.print(start_state);
  if (start_state == ACTIVATED){
    start = true;
  }
  else{
    start = false;
  }
  Serial.print(start);
  
  if (start == false){

    servo.write(180);

    servo2.write(0);
   
    servo3.write(0);
    player.stop();
    alarm_active = false;
    digitalWrite(LED1,LOW);

    Serial.print(" Switch is on, Blocking everything ");


    
  }
  else{
    if (sensorValue >5 && alarm_active==false){
    
    alarm_active = true;
    delay(50);
    servo.write(90);
    servo2.write(90);
    servo3.write(90);
    Serial.print(" Doors Opened ");
    delay(50);}
    if (alarm_active){
    
    digitalWrite(LED1,HIGH);
    
    delay(500);
    alarm();
  }}
  
  

}




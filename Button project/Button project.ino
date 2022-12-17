
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"



static const uint8_t PIN_MP3_TX = 10;
static const uint8_t PIN_MP3_RX = 9;

const int buttonPin2 = 2 ;
int buttonState = 0;

const int buttonPin3 = 3 ;
int buttonState3 = 0;

const int buttonPin4 = 4 ;
int buttonState4 = 0;

const int buttonPin5 = 5 ;
int buttonState5 = 0;

const int buttonPin6 = 6 ;
int buttonState6 = 0;
const bool isPlaying = false;

SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
# define Acknowledge 0x00
# define ACTIVATED LOW
// Create DFPlayer Object
DFRobotDFPlayerMini player;

void setup(){
  pinMode(buttonPin2,INPUT);
  digitalWrite(buttonPin2,HIGH);
  pinMode(buttonPin3,INPUT);
  digitalWrite(buttonPin3,HIGH);
  pinMode(buttonPin4,INPUT);
  digitalWrite(buttonPin4,HIGH);
  pinMode(buttonPin5,INPUT);
  digitalWrite(buttonPin5,HIGH);
  pinMode(buttonPin6,INPUT);
  digitalWrite(buttonPin6,HIGH);


  Serial.begin(9600);
  softwareSerial.begin(9600);
  if (player.begin(softwareSerial)) {
    Serial.print("OK");
    // set volume
    player.volume(30);
  }
  else{
    Serial.print("Error In connecting to DFPlayer"); 
  }
}
void loop(){
  buttonState = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);
  Serial.print(ACTIVATED);
  delay(200);
  if (buttonState == ACTIVATED){
    Serial.print("Playing #1");
    player.play(1);
    delay(300);
  }
  else if (buttonState3 == ACTIVATED){
    Serial.print("Playing #2");
    player.play(2);
    delay(300);
  }
  else if (buttonState4 == ACTIVATED){
    Serial.print("Playing #3");
      player.play(3);
      delay(300);
  }
  else if (buttonState5 == ACTIVATED){
    Serial.print("Playing #4");
    player.play(4);
    delay(300);
  }
  else if (buttonState6 == ACTIVATED){
    Serial.print("Playing #5");
    player.play(5);
    delay(300);
  }

    

}
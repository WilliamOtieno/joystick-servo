#include <Arduino.h>
#include <Servo.h>

const int ledPin = 13;
const int xPin = A0;                                               
const int yPin = A1;
const int switchPin = 2;
const int servoxPin = 10;
const int servoyPin = 11; 

int xValue;
int yValue;
int X_pos = 90;
int Y_pos = 90;

volatile int switchState = 0;
 
Servo servox;
Servo servoy;

void switchISR()
{
  switchState = digitalRead(switchPin);
  digitalWrite(ledPin, switchState);
}

void setup() 
{
  pinMode (xPin, INPUT) ;                     
  pinMode (yPin, INPUT) ;
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
  servox.attach(servoxPin ); 
  servoy.attach(servoyPin); 
  servox.write(X_pos);
  servoy.write(Y_pos);
  attachInterrupt(digitalPinToInterrupt(switchPin), switchISR, CHANGE);
}

void loop() 
{
  xValue = analogRead(xPin);  
  yValue = analogRead(yPin);
// For X-Axis Servo
  if (xValue < 300)
  {
    if (X_pos < 10) 
    {
      // Do Nothing 
    } 
    else
    {
      X_pos = X_pos - 5;
      servox.write(X_pos);
      delay(100); 
    } 
  } 
  
  if (xValue > 700)
  {
    if (X_pos > 160)
    {
      // Do Nothing  
    }
    else
    {
      X_pos = X_pos + 5;
      servox.write(X_pos);
      delay(100);
    }
  }
// For Y-Axis Servo
if (yValue < 300)
  {
    if (Y_pos < 10) 
    {
      // Do Nothing 
    } 
    else
    {
      Y_pos = Y_pos - 5;
      servoy.write(Y_pos);
      delay(100); 
    } 
  } 
  
  if (yValue > 700)
  {
    if (Y_pos > 160)
    {
      // Do Nothing  
    }
    else
    {
      Y_pos = Y_pos + 5;
      servoy.write(Y_pos);
      delay(100);
    }
  }
}


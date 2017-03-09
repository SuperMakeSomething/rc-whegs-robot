/* RC Whegs Robot Code (RC Whegs Robot - Super Make Something Episode 10)
 * by: Alex - Super Make Something
 * date: October 23rd, 2016
 * license: Creative Commons - Attribution - Non-Commercial.  More information available at: http://creativecommons.org/licenses/by-nc/3.0/
 */

/*
 * This code contains the follow functions:
 * - void setup(): initializes Arduino output pins
 * - void loop(): main loop
*/

// RF Receiver related pins and variables
int analogPin1=A3;
int analogPin2=A2;
int analogPin3=A1;
int analogPin4=A0;

int buttonThresh=50;

int valPin1=0;
int valPin2=0;
int valPin3=0;
int valPin4=0;

//Motor 1 related pins
int in1Motor1=4;
int in2Motor1=5;
int pwmMotor1=3;

//Motor 2 related pins
int in1Motor2=7;
int in2Motor2=8;
int pwmMotor2=9;

void setup() 
{

  //Set pins connected to TB6612 Motor Driver Breakout board to output
  pinMode(in1Motor1,OUTPUT);
  pinMode(in2Motor1,OUTPUT);
  pinMode(in1Motor2,OUTPUT);
  pinMode(in2Motor2,OUTPUT);
}

void loop() 
{

  //Read RF receiver pins
  valPin1=analogRead(analogPin1);
  valPin2=analogRead(analogPin2);
  valPin3=analogRead(analogPin3);
  valPin4=analogRead(analogPin4);

  if (valPin1>buttonThresh) //move forward
  {
    analogWrite(pwmMotor1,255);
    analogWrite(pwmMotor2,255);
    digitalWrite(in1Motor1,HIGH);
    digitalWrite(in2Motor1,LOW);
    digitalWrite(in1Motor2,LOW);
    digitalWrite(in2Motor2,HIGH);
  }

  else if (valPin2>buttonThresh) //turn right
  {
    analogWrite(pwmMotor1,128);
    analogWrite(pwmMotor2,255);
    digitalWrite(in1Motor1,HIGH);
    digitalWrite(in2Motor1,LOW);
    digitalWrite(in1Motor2,LOW);
    digitalWrite(in2Motor2,HIGH);
  }

  else if (valPin3>buttonThresh) //turn left
  {
    analogWrite(pwmMotor1,255);
    analogWrite(pwmMotor2,128);  
    digitalWrite(in1Motor1,HIGH);
    digitalWrite(in2Motor1,LOW);
    digitalWrite(in1Motor2,LOW);
    digitalWrite(in2Motor2,HIGH);
  }

  else if (valPin4>buttonThresh) //move backward
  {
    analogWrite(pwmMotor1,255);
    analogWrite(pwmMotor2,255);
    digitalWrite(in1Motor1,LOW);
    digitalWrite(in2Motor1,HIGH);
    digitalWrite(in1Motor2,HIGH);
    digitalWrite(in2Motor2,LOW);
  }

  else //don't move
  {
    analogWrite(pwmMotor1,0);
    analogWrite(pwmMotor2,0);
  }
  
}

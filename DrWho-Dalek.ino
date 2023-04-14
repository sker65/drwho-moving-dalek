#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// a maximum of eight servo objects can be created

int pos = 90;    // variable to store the servo position

boolean moving = false;

#define SOL_DALEK 4
#define OPTO 5

void setup()
{
  myservo.attach(3);  // attaches the servo on pin 3 to the servo object
  pinMode(SOL_DALEK,INPUT);
  pinMode(OPTO, OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite( OPTO, HIGH);
  digitalWrite( 13, LOW);
  myservo.write(90);
  //Serial.begin(9600);
}

#define MAX_POS 170
#define STEP 2

boolean forward = true;

void loop()
{
//    myservo.write(90);

  boolean moving = (digitalRead(SOL_DALEK) == LOW);
  digitalWrite(13, moving);

  if( pos >= 92 || pos <= 88 ) {
    digitalWrite(OPTO,LOW);
  } else {
    digitalWrite(OPTO,HIGH);
  }

  if( moving || pos >= 92 || pos <= 88  ) {

    if( pos < MAX_POS && forward ) {
      pos += STEP;
    }

    if( pos >= 0 && !forward ) {
      pos -= STEP;
    }

    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    
    
    if( pos >= MAX_POS ) {
      forward = false;
    }
    if( pos <= 0 ) {
      forward = true;
    }
    
    //Serial.println(pos);

  } else {
    myservo.write(90);  
  }
  
}

#include <Servo.h>

Servo dalek;  // create servo object to control a servo
// a maximum of eight servo objects can be created

#define SOL_DALEK 4
#define OPTO 5
#define SWITCH_LED 13
#define ZERO_POS 90
#define MAX_POS 170
#define MIN_POS 0
#define STEP 2
#define ZEROPOS_DELTA 4

int pos = ZERO_POS;    // variable to store the servo position

boolean moving = false;

void setup()
{
  dalek.attach(3);  // attaches the servo on pin 9 to the servo object
  pinMode(SOL_DALEK,INPUT);
  pinMode(OPTO, OUTPUT);
  pinMode(SWITCH_LED,OUTPUT);
  digitalWrite( OPTO, HIGH);
  dalek.write(90);
  //Serial.begin(9600);
}


boolean forward = true;

void loop()
{
//    dalek.write(90);

  boolean moving = (digitalRead(SOL_DALEK) == LOW);
  //digitalWrite(13, moving);

  if( pos >= ZERO_POS+ZEROPOS_DELTA || pos <= ZERO_POS-ZEROPOS_DELTA ) {
    digitalWrite(OPTO,HIGH);
    digitalWrite( SWITCH_LED, HIGH);
  } else {
    digitalWrite(OPTO,LOW);
    digitalWrite( SWITCH_LED, LOW);
  }

  if( moving || pos >= ZERO_POS+ZEROPOS_DELTA || pos <= ZERO_POS-ZEROPOS_DELTA  ) {

    if( pos < MAX_POS && forward ) {
      pos += STEP;
    }

    if( pos >= MIN_POS && !forward ) {
      pos -= STEP;
    }

    dalek.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    
    
    if( pos >= MAX_POS ) {
      forward = false;
    }
    if( pos <= MIN_POS ) {
      forward = true;
    }
    
    //Serial.println(pos);

  } else {
    dalek.write(ZERO_POS);  
  }
  
}



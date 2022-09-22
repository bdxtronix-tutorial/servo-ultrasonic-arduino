#include <Servo.h>

int servoPin = 11;
int triggerPin = 4;
int echoPin = 6;
Servo myservo;
 
void setup() {
  Serial.begin (9600);
  pinMode (triggerPin, OUTPUT);
  pinMode (echoPin, INPUT);
  myservo.attach (servoPin); 
}

void loop() { 
  float distance = readUltrasonicDistance();
  Serial.println(distance);

  distance = constrain (distance, 0, 15);
  int angle = map (distance, 0, 15, 0, 180);
  myservo.write (angle);

  }

  long readUltrasonicDistance()
  {
    pinMode (triggerPin, OUTPUT);
    digitalWrite (triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite (triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite (triggerPin, LOW);
    pinMode (echoPin, INPUT);
    float cm = 0.01723 * pulseIn(echoPin, HIGH);

    return cm;
  }

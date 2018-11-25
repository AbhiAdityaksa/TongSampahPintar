#define trigpin 9
#define echopin 8
#define ledred 7

#include <Servo.h>

Servo servo;

float duration, distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode (echopin,INPUT);
  pinMode (ledred, OUTPUT);
  servo.attach(10);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigpin,LOW);
  duration = pulseIn(echopin, HIGH);
  distance = (duration/2)*0.0343;

  if (distance <= 30){
    digitalWrite(ledred,HIGH);
    Serial.println("Silakan");
    servo.write(90);
  }else{
    digitalWrite(ledred,LOW);
    servo.write(0);
    Serial.print(distance);
    Serial.println(" cm");
    delay(1000);
  }
  delayMicroseconds(10);
}

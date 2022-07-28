#include <Servo.h>
#define trigPin 22
#define echoPin 23
Servo servo1;
Servo servo2;
void setup()
{
 Serial.begin (9600);
 servo1.attach(53);
 servo2.attach(52);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(53,OUTPUT);
 pinMode(52,OUTPUT);
 servo1.write(0);
 servo2.write(180);
}
void loop()
{
 long duration, distance;
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 2.91;
 if (distance < 50)
 {
  Serial.println("Distance: ");
  Serial.println(distance);
  servo1.write(90);
  servo2.write(90);
  delay(1000);
 }
 else
 {
  servo1.write(0);
  servo2.write(180); 
 }
 if (distance > 50 || distance <= 0)
 {
  Serial.println("The distance is more than 50 mm");
 }
 else
 {
  Serial.println("Distance: ");
  Serial.println(distance);
  delay(1000);
 }
 delay(1000);
}

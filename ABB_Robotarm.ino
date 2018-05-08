#include <SoftwareSerial.h> // TX RX software library for bluetooth

#include <Servo.h> // servo library 
Servo Rotate, Stretch, Height, Grab; // servo name

void setup()
{
  Rotate.attach(3); // attach servo wires to designated pins
  Stretch.attach(5);
  Height.attach(6);
  Grab.attach(7);
  
  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
}

void loop()
{
  //Read from bluetooth and write to usb serial
  if(bluetooth.available()>= 2 )
  {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 *256) + servopos;

    if (realservo >= 1000 && realservo <1180) {
      int servo1 = realservo;
      servo1 = map(servo1, 1000, 1180, 0, 180);
      Rotate.write(servo1);
      delay(10);
    }
    if (realservo >= 2000 && realservo <2180) {
      int servo2 = realservo;
      servo2 = map(servo2, 2000, 2180, 0, 180);
      Stretch.write(servo2);
      delay(10);
    }
    if (realservo >= 3000 && realservo <3180) {
      int servo3 = realservo;
      servo3 = map(servo3, 3000, 3180, 0, 180);
      Height.write(servo3);
      delay(10);
    }
    if (realservo >= 4000 && realservo <3180) {
      int servo4 = realservo;
      servo4 = map(servo4, 4000, 4180, 0, 180);
      Grab.write(servo4);
      delay(10);
  }
}
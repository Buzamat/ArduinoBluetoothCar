/* Serial Loop */
#include <AFMotor.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#define rxPin 0
#define txPin 1
SoftwareSerial mySerial(rxPin, txPin); // RX, TX
Servo myservo;
AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);
AF_DCMotor motor3(3, MOTOR12_64KHZ);
AF_DCMotor motor4(4, MOTOR12_64KHZ);
char command = 'S';
bool fLight = false;
bool bLight = false;
bool honk = false;
bool manual = false;
byte dragSelect = 0;
byte wheelRotation = 80;
byte carSpeed = 255;
void setup() {
  Serial.begin(9600);  //serial
  mySerial.begin(38400); //bluetooth
  myservo.attach(10);
  motor1.setSpeed(carSpeed);
  motor2.setSpeed(carSpeed);
  motor3.setSpeed(carSpeed);
  motor4.setSpeed(carSpeed);
  myservo.write(wheelRotation);
}

void loop() {
  while (mySerial.available()) {
    command = mySerial.read();
    //Serial.print(command);
    switch (command) {
      case 'X':
        manual = true;
        break;
      case 'x':
        manual = false;
        break;
      case 'S':
        if (manual == false) {
          tilt(5);
        }
        stopCar();
        break;
      case 'R':
        if (manual == false) {
          tilt(5);
        }
        turnRight();
        break;
      case 'L':
        if (manual == false) {
          tilt(5);
        }
        turnLeft();
        break;
      case 'F':
        if (manual == false) {
          tilt(5);
        }
        driveCar();
        break;
      case 'B':
        if (manual == false) {
          tilt(5);
        }
        reverseCar();
        break;
      case 'I':
        if (manual == false) {
          tilt(10);
          driveCar();
        }
        break;
      case 'G':
        if (manual == false) {
          tilt(0);
          driveCar();
        }
        break;
      case 'J':
        if (manual == false) {
          tilt(10);
          reverseCar();
        }
        break;
      case 'H':
        if (manual == false) {
          tilt(0);
          reverseCar();
        }
        break;
      case 'V':
        honk = true;
        honkCar();
        break;
      case 'v':
        honk = false;
        honkCar();
        break;
      case 'W':
        fLight = true;
        carLights();
        break;
      case 'w':
        fLight = false;
        carLights();
        break;
      case 'U':
        bLight = true;
        carLights();
        break;
      case 'u':
        bLight = false;
        carLights();
        break;
        case 'D':
                if (manual == false) {
          tilt(5);
        }
        stopCar();
        break;
      default:
        if (command == 'q')dragSelect = 10;
        else dragSelect = command - 48;
        if (manual) {
          tilt(dragSelect);
        }
        else {
  carSpeed = dragSelect * 25;
  if (dragSelect == 10) {
    carSpeed += 5;
  }
  motor1.setSpeed(carSpeed);
  motor2.setSpeed(carSpeed);
  motor3.setSpeed(carSpeed);
  motor4.setSpeed(carSpeed);
        }
        break;
    }
  }
}


void stopCar() {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
}

void driveCar() {
    motor1.run(BACKWARD); 
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD); 
}

void reverseCar() {


        motor1.run(FORWARD); 
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD); 
}

void turnRight() {
    motor1.run(BACKWARD); 
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(BACKWARD); 
}
void turnLeft() {
    motor1.run(FORWARD); 
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(FORWARD); 
}

void tilt(byte amount) {
  wheelRotation = 35 + amount * 9;
  myservo.write(wheelRotation);
}

/*
void setCarSpeed(byte amount) {
  carSpeed = amount * 25;
  if (amount == 10) {
    carSpeed += 5;
  }
  motor1.setSpeed(carSpeed);
  motor2.setSpeed(carSpeed);
  motor3.setSpeed(carSpeed);
  motor4.setSpeed(carSpeed);
}*/


void carLights() {
  if (fLight) {
    Serial.println("Front Lights ON");
  }
  else Serial.println("Front Lights OFF");
  if (bLight) {
    Serial.println("Back Lights ON");
  }
  else Serial.println("Back Lights OFF");
}

void honkCar() {
  if (honk) {
    Serial.println("HONK ON!");
  }
  else Serial.println("HONK off");
}

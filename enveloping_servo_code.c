#include <Servo.h>

Servo myservo;
const int threshValue = 30; // Required threshold to turn servo
const int servoPin = 9; // Pin attachment of the servo
const int sensorPin = A3; // Analog pin connected to the sensor
const int windowSize = 500; // Size of the trigger window
int triggerWindow[windowSize];
int windowIndex = 0;

void setup() {
  myservo.attach(servoPin); // Attaching servo to pin
  Serial.begin(9600); // Start serial communication
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Read the input on analog pin A3
  
  if (sensorValue < 0) {
    sensorValue = -sensorValue;
  }
  
  triggerWindow[windowIndex] = sensorValue;
  windowIndex = (windowIndex + 1) % windowSize;
  
  int sum = 0;
  for (int i = 0; i < windowSize; i++) {
    sum += triggerWindow[i];
  }
  
  int trigger = sum / windowSize;
  Serial.println(trigger) ;


  if (trigger > threshValue) {
    myservo.write(180); // Turns servo to flexed position
  } else {
    myservo.write(0); // Turns servo back to rest position
  }
  
  //delay(300); // Delay in between reads for stability
}

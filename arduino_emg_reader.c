void setup()
{
  Serial.begin(9600);   // initialize serial communication at 9600 bits per second:
}

void loop() 
{
  int sensorValue = analogRead(A3);  // read the input on analog pin 3
  Serial.println(sensorValue);   // print out the value you read
  delay(500);        // delay in between reads for stability
}

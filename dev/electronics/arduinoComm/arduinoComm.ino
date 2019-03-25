
int sensorValues[] = {100,100};

void setup() {
  Serial.begin(9600); // set the baud rate
  Serial.println("Ready"); // print "Ready" once

  pinMode(10, INPUT);
  pinMode(11, INPUT);

}

void loop() {

  // MESSAGE byte PROTOCOL [ID = 0->99, value = 100 -> 199]

  // ANALOG READING
  int minSensor = 500;
  int maxSensor = 1024;
  sensorValues[0] = map(analogRead(A0),minSensor, maxSensor,100,200);
  sensorValues[1] = map(analogRead(A1),minSensor, maxSensor,100,200);

  sensorValues[0] = constrain(sensorValues[0], 100, 200);
  sensorValues[1] = constrain(sensorValues[1], 100, 200);
  
  sendSensorData(0,sensorValues[0]);
  sendSensorData(1,sensorValues[1]);

  //Serial.println("---");

  /*
  // DIGITAL PRE-TEST
  if (digitalRead(10) == HIGH) {
    sendSensorData(0, 10);
  }
  if (digitalRead(11) == HIGH) {
    sendSensorData(1, 20);
  }
  */

  delay(100);


}

void sendSensorData(int id, int value) {

  Serial.println(id);
  Serial.println(value);
  //delay(500);


}



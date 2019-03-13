
int sensorValues[] = {100,100,100,100};

void setup() {
  Serial.begin(9600); // set the baud rate
  Serial.println("Ready"); // print "Ready" once

  pinMode(10, INPUT);
  pinMode(11, INPUT);

}

void loop() {

  // MESSAGE byte PROTOCOL [ID = 0->99, value = 100 -> 199]

  // ANALOG READING
  sensorValues[0] = analogRead(A0);
  sensorValues[1] = analogRead(A1);
  sensorValues[2] = analogRead(A2);
  sensorValues[3] = analogRead(A3);

  float average1 = float(sensorValues[0] + sensorValues[1]) / 2;
  float average2 = float(sensorValues[2] + sensorValues[3]) / 2;
  
  sendSensorData(0,average1);
  sendSensorData(1,average2);
  
  // DIGITAL PRE-TEST
  if (digitalRead(10) == HIGH) {
    sendSensorData(0, 10);
  }
  if (digitalRead(11) == HIGH) {
    sendSensorData(1, 20);
  }


}

void sendSensorData(int id, int value) {

  Serial.println(id);
  Serial.println(value);
  //delay(500);


}



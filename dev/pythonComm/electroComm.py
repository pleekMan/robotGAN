from time import sleep
import serial
serialComm = serial.Serial('/dev/tty.usbmodem1421', 9600) # Establish the connection on a specific port

sensorData = [0,0]
selectedId = 0
while True:

     byteData = serialComm.readline()
     intData = int(byteData)
     print("Recieved: " + str(intData))  

     if intData < 10:
          print("Setting UserId => " + str(intData))
          selectedId = intData
     else:
          print("Setting Data")
          sensorData[selectedId] = intData

     print("SensorData => " + str(sensorData))
     print("==================================")



     sleep(0.01)

     

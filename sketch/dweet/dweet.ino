/*
  dweet
  Post your sensor data or read it from dweet.io
  To be used in conjunction with the Python wrapper for dweet
 
  Code by:
  Ankit Daftery @ankitdaf
  2 June 2014
  
  This example code is licensed under the GPL v3 license.
 */

#include <Process.h>

String guid = "guid";
int sensor1 = A0;
int sensor2 = A1;

void setup() {
  Bridge.begin();
  Serial.begin(9600);
  while(!Serial);  // wait for Serial port to connect.
  Serial.println("beginning");
}


void loop () {

  // get_dweet();   // Get sensor value
  int sensVal = analogRead(sensor1);
  String data = "{'sensor1':'";
  data += (String) sensVal;
  data += "','sensor2':'";
  sensVal = analogRead(sensor2);
  data += (String) sensVal;
  data += "'}";
  send_dweet(data);
  delay(5000);

}

void get_dweet() {
  Process dweet;
  dweet.runShellCommand("python /mnt/sda1/dweet/sdcard/dweet.py guid get");  // upload the file we just wrote to to Dropbox
  while(dweet.available()) {
    char c=dweet.read();
    Serial.print(c);  // Display the response
  } 
}

void send_dweet(String data) {
  Process dweet;
  String final = "python dweet.py guid post \"" + data+ "\"";
  Serial.println(final);
  dweet.runShellCommand("python /mnt/sda1/dweet/sdcard/dweet.py guid post \"" + data+ "\""); //{'sensor1':'0','sensor2':'1'}\"");  // upload the file we just wrote to to Dropbox
  while(dweet.available()) {
    char c=dweet.read();
    Serial.print(c);  // Display the response
  }   
}


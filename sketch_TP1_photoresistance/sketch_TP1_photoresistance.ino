/**
 * La led clignote en fonction de la lumière reçu par la photoresistance
 */

int ledPin = 3;
int sensorPin = A4;    // input photoresistance
int sensorValue = 0;  // variable to store the value coming from the sensor
int intensiteLum = 0; // variable d'intensité lumineuse

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
   sensorValue = analogRead(sensorPin);
   intensiteLum = 255 - calibration(300,1024,sensorValue);

   analogWrite(ledPin, intensiteLum); // Allumé qaund il fait jour (comme rétroéclairage samrtphone)

   delay(100);
}

/** 
 * Remet les valuers entre 0 et 255 
 */
int calibration(int valueMin, int valueMax, int value){
  int res;

  res = (value-valueMin)*255/(valueMax-valueMin);

  if(res > 255){
    res = 255;
  }
  
  return res;
}


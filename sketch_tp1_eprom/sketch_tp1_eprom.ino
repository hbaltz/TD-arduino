/**
 * Lecture des bits sur une eprom
 */

void setup() {
  for ( int i = 2 ; i < 10 ; i++){ 
    pinMode(i, INPUT);
  }
  Serial.begin(9600);

}

void loop() {
  unsigned int value = 0;

  for ( int j = 0 ; j < 8 ; j++){ 
    value += digitalRead(j+2) << j;
  }

  Serial.println(value,HEX); 

  delay(1000);
}

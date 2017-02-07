int ledGPIO = 3;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledGPIO, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int inc = 3; // incrément
  int dly = 10; //délai en ms
  
  for(int i =0 ; i <255 ; i=i+inc){
    analogWrite(ledGPIO, i);   // turn the LED on (HIGH is the voltage level)
    delay(dly);                  
  }
  for(int j =255 ; j >0 ; j=j-inc){
    analogWrite(ledGPIO, j);   // turn the LED on (HIGH is the voltage level)
    delay(dly);                  
  }
}

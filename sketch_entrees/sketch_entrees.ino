/**
 * Lorsque l'on pousse le bouton une première fois le bouton clignote, une dexuième fois il s'arrête etc.
 * Montage pull up
 */

 // TODO supprimer les délais : https://www.arduino.cc/en/Tutorial/BlinkWithoutDelay

// Variables globales :
bool blink_status = false;
int buttonPin = 2;
int oldState = LOW;

void setup() {
  pinMode(buttonPin, INPUT); // 2 input
  pinMode(LED_BUILTIN, OUTPUT); // 13 output
}

void loop() {
  int buttonState = digitalRead(buttonPin); // On lit l'état du bouton

  if(buttonState != oldState && buttonState == LOW){ // Si l'état est différent de l'état précédent, on change le statue du button
     blink_status = !blink_status;                   
  }

  if(blink_status){ // Si run = true, on clignote
     clignote(LED_BUILTIN,100);
  }

  oldState = buttonState; // On sauvegarde l'ancien état
}

/**
 * Fais clignoter une led présente en pin avec un delay de dly
 */
void clignote(int pin, int dly){
  digitalWrite(pin, HIGH);   
  delay(dly);                       
  digitalWrite(pin, LOW);    
  delay(dly);  
}

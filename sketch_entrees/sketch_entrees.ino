/**
 * Lorsque l'on pousse le bouton une première fois le bouton clignote, une dexuième fois il s'arrête etc.
 */

bool run = false;
int buttonPin = 2;
int oldState = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin); // On lit l'état du bouton

  if(buttonState != oldState && buttonState == LOW){ // Si l'état est différent de l'état précédent, on change le statue du button
     run = !run;                   
  }

  if(run){ // Si run = true, on clignote
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

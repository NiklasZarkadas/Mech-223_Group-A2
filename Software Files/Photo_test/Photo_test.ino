const int photo = A1;
const int LED = 2;
int gateState = 0; 

void setup() {
  pinMode(photo, INPUT);       //Tells the Arduino that digital pin 2 is going to give it information.
  pinMode(LED, OUTPUT);   //Tells the Arduino that it is going to give commands to digital pin 9.

  Serial.begin(750); 
}

void loop() {
  gateState = analogRead(photo);  //Each time the loop runs, set the value of gateState to be whatever
    Serial.print(gateState);
   Serial.print('\n');
                                              // value is coming in from pin 2.
  if (gateState > 25) {               //If the value of gateState is greater than zero,
    digitalWrite(LED, HIGH);      //turn on the LED by sending high voltage (4.9V) to pin 9.

  }
  else {                                  //Otherwise (that is, if the value of gateState is less than or equal to zero),
    digitalWrite(LED, LOW);     //turn off the LED by sending low voltage (0V) to pin 9.
  }

}
const int CCW= 10;  //  white
const int CW = 5;  //  green 
const int delayTime = 10; // Delay between steps
const int maxPWM = 255;  // Max PWM duty cycle

void setup() {
    pinMode(CCW, OUTPUT);
    pinMode(CW, OUTPUT);
}

void loop() {
 digitalWrite(CCW, HIGH);
 digitalWrite(CW, LOW);

delay(2000);
digitalWrite(CCW, LOW);
 digitalWrite(CW, LOW);
delay(2000);

 digitalWrite(CW, HIGH);
 digitalWrite(CCW, LOW);

delay(2000);
digitalWrite(CCW, LOW);
 digitalWrite(CW, LOW);
 delay(2000);

}

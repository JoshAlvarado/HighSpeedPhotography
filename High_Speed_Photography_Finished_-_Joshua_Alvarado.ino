//Arduino High Speed Photography 5/16/2019 Joshua Alvarado
int cameraPin = 12;
int flashPin = 10;
int soundSensor = A1;
byte soundVal = 0;
int threshold = 150; 
int buttonPin = 11;
int buttonState = LOW;
int lampPin = 13;
int areWeReady = 0;
//int LED = 9;

void setup() {
 pinMode(cameraPin,OUTPUT);
 pinMode(flashPin, OUTPUT);
 pinMode(soundSensor,INPUT);
 pinMode(buttonPin,INPUT);
 pinMode(lampPin, OUTPUT);
 Serial.begin(9600); 
 digitalWrite(lampPin, HIGH);
 pinMode(LED, OUTPUT);
}

void loop() {

buttonState = digitalRead(buttonPin);
//soundVal = analogRead(soundSensor); //only used to test piezo/sound sensor 
//Serial.println(soundVal);
//Serial.print("\t");
//  Serial.print("\t");

if(buttonState == HIGH) {
Serial.println("Button Was Pressed");
digitalWrite(lampPin, LOW); //Turns off light in the room
delay(2000);
digitalWrite(cameraPin, HIGH); //Open shutter
digitalWrite(LED, LOW); // LED off = Everything ready
areWeReady = 1;
}

if(areWeReady == 1 and (analogRead(soundSensor) >= threshold)) {
digitalWrite(cameraPin, LOW); // Close camera shutter 
digitalWrite(flashPin, HIGH); // Turn flash on
Serial.println("Picture Taken");
digitalWrite(flashPin, LOW); // Reset flash
delay(2000);
digitalWrite(lampPin, HIGH); // Turns lights back on
areWeReady = 0; // Reset till button is pressed again
digitalWrite(LED, HIGH); // Turn LED back on
  }
}

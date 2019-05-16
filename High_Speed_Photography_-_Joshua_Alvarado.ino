//Arduino High Speed Photography 5/16/2019 Joshua Alvarado
int cameraPin = 12;
int flashPin = 10;
int soundSensor = A1;
byte soundVal = 0;
int threshold = 170; 
int buttonPin = 11;
int buttonState = LOW;
int lampPin = 13;
int areWeReady = 0;

void setup() {
 pinMode(cameraPin,OUTPUT);
 pinMode(flashPin, OUTPUT);
 pinMode(soundSensor,INPUT);
 pinMode(buttonPin,INPUT);
 pinMode(lampPin, OUTPUT);
 Serial.begin(9600); 
 digitalWrite(lampPin, HIGH);
}

void loop() {
buttonState = digitalRead(buttonPin);
soundVal = analogRead(soundSensor);
Serial.println(soundVal);
Serial.print("\t");
Serial.print("\t");

if(buttonState == HIGH) {
Serial.println("Button Was Pressed");
digitalWrite(lampPin, LOW); //Turns off light in the room
digitalWrite(cameraPin, HIGH); //Open shutter
areWeReady = 1;
}

if(areWeReady == 1 and (soundVal >= threshold)) {
digitalWrite(flashPin, HIGH); // Turn flash on
digitalWrite(cameraPin, LOW); // Close camera shutter 
Serial.println("Picture Taken");
digitalWrite(flashPin, LOW); // Reset flash
delay(1000);
digitalWrite(lampPin, HIGH); // Turns lights back on
areWeReady = 0; // Reset till button is pressed again
  }
}

// to be changed to actual pin # when being made
int lightInputPin = A0;
int onOffLed = 1;

void setup() {
  pinMode(onOffLed, OUTPUT);
  digitalWrite(onOffLed, LOW);
}

void loop() {
 int lightValue = analogRead(lightInputPin);
 findOpenOrClose(lightValue);
}

void findOpenOrClose(int lightvalue) {
  if (lightValue >= 100) {
    digitalWrite(onOffLed, HIGH);
  } else {
    digitalWrite(onOffLed, LOW);
  }
}
int object = 0;

void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  object = digitalRead(2);
  if (object == 0) {
    Serial.println("Object : Detected");
  }
  else {
    Serial.println("Object : Missing!");
  }
}

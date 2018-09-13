int sensorLeft = 0;
int sensorRight = 0;
int valueLeft = 0;
int valueRight = 0;
bool stateLeft = false;
bool stateRight = false;

void setup() {
  pinMode(8, INPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void counterLeft() {
    Serial.print("Left: ");
    Serial.println(valueLeft);
    valueLeft ++;
}

void counterRight() {
    Serial.print("Right: ");
    Serial.println(valueRight);
    valueRight ++;
}

void loop() {
  sensorRight = digitalRead(2);
  sensorLeft = digitalRead(8);

  if (sensorRight==1  & !stateRight) {
    stateRight = true;
    counterRight();
  }
  else if (sensorRight==0  & stateRight) {
    stateRight = false;
  }

  if (sensorLeft==1  & !stateLeft) {
    stateLeft = true;
    counterLeft();
  }
  else if (sensorLeft==0  & stateLeft) {
    stateLeft = false;
  }
}

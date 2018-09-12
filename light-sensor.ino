bool stateLeft = false;
bool stateRight = false;

int objectLeft = 0;
int objectRight = 0;

int contLeft = 0;
int contRight = 0;

// left - 8
// right - 2

void setup() {
  pinMode(8, INPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void sensorLeft() {
  if (stateLeft) {
    Serial.print("Left: ");
    Serial.println(contLeft);
    contLeft ++;
  }
}

void sensorRight() {
  if (stateRight) {
    Serial.print("Right: ");
    Serial.println(contRight);
    contRight ++;
  }
}

void loop() {
  objectRight = digitalRead(2);
  objectLeft = digitalRead(8);

  if (objectRight==1  & stateRight) {
    stateRight = true;
  } else if (objectRight==1  & !stateRight) {
    stateRight = true;
    sensorRight();
  }
  else if (objectRight==0  & stateRight) {
    stateRight = false;
  }

  if (objectLeft==1  & stateLeft) {
    stateLeft = true;
  } else if (objectLeft==1  & !stateLeft) {
    stateLeft = true;
    sensorLeft();
  }
  else if (objectLeft==0  & stateLeft) {
    stateLeft = false;
  }
}

unsigned int right_counter = 0;
bool light_state = false;

void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  int light_sensor = digitalRead(2);

  if (light_sensor == 1  && !light_state) {
    light_state = true;
    right_counter++;
  } else if (light_sensor == 0  && light_state) {
    light_state = false;
  }
}

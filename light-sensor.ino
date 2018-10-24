#define light_port 8

bool light_state = false;
unsigned int right_counter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(light_port, INPUT);
}

void loop() { 
  int light_sensor = digitalRead(light_port);
  
    if (light_sensor == 1 && !light_state) {
      light_state = true;
      Serial.println(right_counter++);
            
    } else if (light_sensor == 0 && light_state) {
      light_state = false;
    }
}

#include "I2Cdev.h" 
#include "MPU6050.h"
#include "Wire.h"

#define light_port 8

bool light_state = false;
unsigned int right_counter = 0; 

MPU6050 giroscope_sensor;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  pinMode(light_port, INPUT);

  giroscope_sensor.initialize();
  if (giroscope_sensor.testConnection())
    Serial.println("Sensor initialized");
  else 
    Serial.println("Error on sensor initialize");
}

void loop() { 
  
  int light_sensor = digitalRead(light_port);
  
    if (light_sensor == 1 && !light_state) {
      light_state = true;
      Serial.println(right_counter++);
            
    } else if (light_sensor == 0 && light_state) {
      light_state = false;
    }
    
  int ax, ay, az; 
  int gx, gy, gz;

  giroscope_sensor.getAcceleration(&ax, &ay, &az);  
  giroscope_sensor.getRotation(&gx, &gy, &gz);

  float ax_m_s2 = ax * (9.81/16384.0);
  float ay_m_s2 = ay * (9.81/16384.0);
  float az_m_s2 = az * (9.81/16384.0);
  float gx_deg_s = gx * (250.0/32768.0);
  float gy_deg_s = gy * (250.0/32768.0);
  float gz_deg_s = gz * (250.0/32768.0);

  String s = "[";
  s += String(ax_m_s2);
  s += " ";
  s += String(ay_m_s2);
  s += " ";
  s += String(az_m_s2);
  s += "] [";
  s += String(gx_deg_s);
  s += " ";
  s += String(gy_deg_s);
  s += " ";
  s += String(gz_deg_s);
  s += "]";

  Serial.println(s);
}

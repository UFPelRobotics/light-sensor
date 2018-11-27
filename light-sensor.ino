#include <ros.h>
#include <std_msgs/String.h>
#define light_port 8

ros::NodeHandle  node;
std_msgs::String light_msg;
ros::Publisher light_pub("right_sensor", &light_msg);
unsigned int right_counter = 0;
bool light_state = false;

void setup() {
  Serial.begin(9600);
  pinMode(light_port, INPUT);
  node.initNode();
  node.advertise(light_pub);
}

void loop() {
  int light_sensor = digitalRead(light_port);
  if (light_sensor == 1  && !light_state) {
    light_state = true;
    char buffer[5];
    String(right_counter++).toCharArray(buffer, 5);
    light_msg.data = buffer;
    light_pub.publish(&light_msg);
  } else if (light_sensor == 0  && light_state) {
    light_state = false;
  }
  node.spinOnce();
}

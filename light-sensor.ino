#include <ros.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Bool.h>
#define light_port 12

unsigned int right_counter = 0;
bool light_state = false;

void clearCounter(const std_msgs::Bool &shouldClear) {
  if (shouldClear.data)
    right_counter = 0;
}

ros::NodeHandle  node;
std_msgs::Int16 light_msg;
ros::Publisher light_pub("right_sensor", &light_msg);
ros::Subscriber<std_msgs::Bool> clear_counter("pattern", &clearCounter);

void setup() {
  Serial.begin(9600);
  pinMode(light_port, INPUT);
  node.initNode();
  node.advertise(light_pub);
  node.subscribe(clear_counter);
}

void loop() {
  int light_sensor = digitalRead(light_port);
  if (light_sensor == 1  && !light_state) {
    light_state = true;
    light_msg.data = right_counter++;
    light_pub.publish(&light_msg);
  } else if (light_sensor == 0  && light_state) {
    light_state = false;
  }
  node.spinOnce();
}

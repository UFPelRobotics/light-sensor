#include <ros.h>
#include <std_msgs/String.h>
#define light_port 8

ros::NodeHandle  node;
std_msgs::String light_msg;
ros::Publisher light_pub("right_sensor", &light_msg);
ros::Subscriber<std_msgs::String> movement_sub("movement", &getDirectionFromTopic);
unsigned int right_counter = 0;
bool light_state = false;

void getDirectionFromTopic(const std_msgs::String &direction_msg) {
  _move(direction_msg.data[0]);
}

void setup() {
  Serial.begin(9600);
  pinMode(light_port, INPUT);
  node.initNode();
  node.advertise(light_pub);
  node.subscribe(movement_sub);
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

void _move(char control){
  switch (control) {
    case 'd':
      right_counter = 0;
      break;
    case 'a':
      right_counter = 0;
      break;
    case 'w':
      right_counter = 0;
      break;
    case 's':
      right_counter = 0;
      break;
     case 'p':
      right_counter = 0;
      break;
  }
}

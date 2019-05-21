#include <ros.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Bool.h>

#define odometryPin 13

unsigned int right_counter = 0;
bool odometry_state = false;

void clearCounter(const std_msgs::Bool &shouldClear)
{
  if (shouldClear.data)
    right_counter = 0;
}

ros::NodeHandle node;
std_msgs::Int16 value_odometry;
ros::Publisher odometry_pub("right_sensor", &value_odometry);
ros::Subscriber<std_msgs::Bool> clear_counter("pattern", &clearCounter);

void setup()
{
  Serial.begin(9600);
  pinMode(odometryPin, INPUT);
  node.initNode();
  node.advertise(odometry_pub);
  node.subscribe(clear_counter);
}

void loop()
{
  int odometry_sensor = digitalRead(odometryPin);
  if (odometry_sensor == 1 && !odometry_state)
  {
    odometry_state = true;
    value_odometry.data = right_counter++;
    odometry_pub.publish(&value_odometry);
  }
  else if (odometry_sensor == 0 && odometry_state)
  {
    odometry_state = false;
  }
  node.spinOnce();
}

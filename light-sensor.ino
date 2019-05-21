#include <ros.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Bool.h>

#define odometryPin 2

unsigned int right_counter = 0;
unsigned int tmp_counter = 0;

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
  attachInterrupt(digitalPinToInterrupt(odometryPin), counter, RISING);
}

void loop()
{
  if (right_counter == 10)
  {
    value_odometry.data = right_counter;
    odometry_pub.publish(&value_odometry);
    right_counter = 0;
  }
  node.spinOnce();
}

void counter()
{
  tmp_counter++;
  if (tmp_counter == 4)
  {
    tmp_counter = 0;
    right_counter++;
  }
}

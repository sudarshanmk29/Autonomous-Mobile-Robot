#include<ArduinoHardware.h>
#include <ros.h>
#include<ros/time.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Float32.h>

//left motor Pins
#define enA 7   
#define IN1 14
#define IN2 15

//right motor pins
#define enB 6    
#define IN3 16
#define IN4 17

struct velocity
{
  int velocity;
}*left,*right;

ros::NodeHandle nh;

std_msgs::Int32 dc;
std_msgs::Float32 vel;
ros::Publisher duty_cycle("PWM", &dc);
ros::Publisher velocity("vel", &vel);


void onTwist(const geometry_msgs::Twist &msg);

//Subscriber
ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel",onTwist);  

void setup() 
{
  Serial.begin(9600);
   
  pinMode(enA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(duty_cycle);
  nh.advertise(velocity);
}

void loop() 
{
   nh.spinOnce();
}

void onTwist(const geometry_msgs::Twist &msg)
{
  //Forward
  if(msg.linear.x > 0.0 && msg.angular.z==0.0)
  {
    float lrpm = (msg.linear.x-(msg.angular.z*0.1))/0.035;
    float ldc = (39-lrpm)/0.6;
    left->velocity = (255*ldc)/100;
 
    analogWrite(enA, left->velocity);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    dc.data = left->velocity;
    duty_cycle.publish(&dc);

    float rrpm = (msg.linear.x+(msg.angular.z*0.1))/0.035;
    float rdc = (39-rrpm)/0.6;
    right->velocity = (255*rdc)/100;

    analogWrite(enB, right->velocity);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    
    dc.data = right->velocity;
    duty_cycle.publish(&dc);
    
    vel.data = lrpm;
    velocity.publish(&vel);
    vel.data = rrpm;
    velocity.publish(&vel);

  }

  //REVERSE
  else if(msg.linear.x < 0.0 && msg.angular.z == 0.0)
  {
    float lrpm = (msg.linear.x-(msg.angular.z*0.1))/0.035;
    float ldc = (39-lrpm)/0.6;
    left->velocity = (255*ldc)/100;
      
    analogWrite(enA, left->velocity);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    dc.data = left->velocity;
    duty_cycle.publish(&dc);

    float rrpm = (msg.linear.x+(msg.angular.z*0.1))/0.035;
    float rdc = (39-rrpm)/0.6;
    right->velocity = (255*rdc)/100;
    
    analogWrite(enB, right->velocity);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    dc.data = right->velocity;
    duty_cycle.publish(&dc);
    
    vel.data = lrpm;
    velocity.publish(&vel);
    vel.data = rrpm;
    velocity.publish(&vel);

  }

  //LEFT
  else if(msg.angular.z > 0.0 && msg.linear.x == 0.0)
  {
    float lrpm = (msg.linear.x-(msg.angular.z*0.1))/0.035;
    float ldc = (39-lrpm)/0.6;
    left->velocity = (255*ldc)/100;
    
    analogWrite(enA, left->velocity);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    dc.data = left->velocity;
    duty_cycle.publish(&dc);
    
    float rrpm = (msg.linear.x+(msg.angular.z*0.1))/0.035;
    float rdc = (39-rrpm)/0.6;
    right->velocity = (255*rdc)/100;
    
    analogWrite(enB, right->velocity);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    dc.data = right->velocity;
    duty_cycle.publish(&dc);
    
    vel.data = lrpm;
    velocity.publish(&vel);
    vel.data = rrpm;
    velocity.publish(&vel);

  }

  //RIGHT
  else if(msg.angular.z < 0.0 && msg.linear.x == 0.0)
  {
    float lrpm = (msg.linear.x-(msg.angular.z*0.1))/0.035;
    float ldc = (39-lrpm)/0.6;
    left->velocity = (255*ldc)/100;
   
    analogWrite(enA, left->velocity);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    dc.data = left->velocity;
    duty_cycle.publish(&dc);
    
    float rrpm = (msg.linear.x+(msg.angular.z*0.1))/0.035;
    float rdc = (39-rrpm)/0.6;
    right->velocity = (255*rdc)/100;
    
    analogWrite(enB, right->velocity);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    dc.data = right->velocity;
    duty_cycle.publish(&dc);
    
    vel.data = lrpm;
    velocity.publish(&vel);
    vel.data = rrpm;
    velocity.publish(&vel);
  }
  
  //RIGHT Circle fwd
  else if(msg.angular.z < 0 && msg.linear.x>0)
  {
    float lrpm = (msg.linear.x-(msg.angular.z*0.1))/0.035;
    float ldc = (39-lrpm)/0.6;
    left->velocity = (255*ldc)/100;
   
    analogWrite(enA, left->velocity);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    dc.data = left->velocity;
    duty_cycle.publish(&dc);
    
    float rrpm = (msg.linear.x+(msg.angular.z*0.1))/0.035;
    float rdc = (39-rrpm)/0.6;
    right->velocity = (255*rdc)/100;
    
    analogWrite(enB, right->velocity);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    dc.data = right->velocity;
    duty_cycle.publish(&dc);
        
    vel.data = lrpm;
    velocity.publish(&vel);
    vel.data = rrpm;
    velocity.publish(&vel);
  }

  //RIGHT Circle reverse
  else if(msg.angular.z > 0 && msg.linear.x < 0)
  {
    float lrpm = (msg.linear.x-(msg.angular.z*0.1))/0.035;
    float ldc = (39-lrpm)/0.6;
    left->velocity = (255*ldc)/100;
    
    analogWrite(enA, left->velocity);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    dc.data = left->velocity;
    duty_cycle.publish(&dc);
    
    float rrpm = (msg.linear.x+(msg.angular.z*0.1))/0.035;
    float rdc = (39-rrpm)/0.6;
    right->velocity = (255*rdc)/100;
    
    analogWrite(enB, right->velocity);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    dc.data = right->velocity;
    duty_cycle.publish(&dc);
        
    vel.data = lrpm;
    velocity.publish(&vel);
    vel.data = rrpm;
    velocity.publish(&vel);
  }
  
  //LEFT Circle fwd
  else if(msg.angular.z > 0 && msg.linear.x > 0)
  {
    float lrpm = (msg.linear.x-(msg.angular.z*0.1))/0.035;
    float ldc = (39-lrpm)/0.6;
    left->velocity = (255*ldc)/100;
   
    analogWrite(enA, left->velocity);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    
    dc.data = left->velocity;
    duty_cycle.publish(&dc);
    
    float rrpm = (msg.linear.x+(msg.angular.z*0.1))/0.035;
    float rdc = (39-rrpm)/0.6;
    right->velocity = (255*rdc)/100;
    
    analogWrite(enB, right->velocity);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    dc.data = right->velocity;
    duty_cycle.publish(&dc);
        
    vel.data = lrpm;
    velocity.publish(&vel);
    vel.data = rrpm;
    velocity.publish(&vel);
  }

  //LEFT Circle reverse
  else if(msg.angular.z < 0 && msg.linear.x < 0)
  {    
    float lrpm = (msg.linear.x-(msg.angular.z*0.1))/0.035;
    float ldc = (39-lrpm)/0.6;
    left->velocity = (255*ldc)/100;
    
    analogWrite(enA, left->velocity);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    dc.data = left->velocity;
    duty_cycle.publish(&dc);
    
    float rrpm = (msg.linear.x+(msg.angular.z*0.1))/0.035;
    float rdc = (39-rrpm)/0.6;
    right->velocity = (255*rdc)/100;
    
    analogWrite(enB, right->velocity);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    dc.data = right->velocity;
    duty_cycle.publish(&dc);
        
    vel.data = lrpm;
    velocity.publish(&vel);
    vel.data = rrpm;
    velocity.publish(&vel);
  }


  //STOP
  else
  {
    float lrpm = 0.0;
    left->velocity = 0;

    
    analogWrite(enA, left->velocity);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    dc.data = left->velocity;
    duty_cycle.publish(&dc);
    
    float rrpm = 0.0;
    right->velocity = 0;

     
    analogWrite(enB, right->velocity);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    
    dc.data = right->velocity;
    duty_cycle.publish(&dc);
    
    vel.data = lrpm;
    velocity.publish(&vel);
    vel.data = rrpm;
    velocity.publish(&vel);
  }
}

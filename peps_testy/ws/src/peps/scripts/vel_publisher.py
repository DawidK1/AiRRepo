#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist
import time
pub = rospy.Publisher('cmd_vel', Twist, queue_size=10)

rospy.init_node('velocity_publisher')

rate = rospy.Rate(10)

my_msg = Twist()



pub.publish(my_msg)


x =2
i =0
while not rospy.is_shutdown():
	
	i = i + 1
	if i == 40:
		i = 0
		x = -x	

	my_msg.linear.x = x
	
	my_msg.linear.y = x*i/20
	
	my_msg.angular.z = 0

    	pub.publish(my_msg)
	
    	rate.sleep()
	



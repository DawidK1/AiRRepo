#!/usr/bin/env python
import rospy
import numpy
from peps.msg import gps_data
from gazebo_msgs.msg import ModelStates
from geometry_msgs.msg import Pose
import time
import tf



#Params

#beacon 1
radius_b1 = 0.208344
theta_b1 = 1.2494
fi_b1 = 0.305934

#beacon 2
radius_b2 = 1.97375
theta_b2 = 0
fi_b2 = 1.570796




def callback(data):
	global i
	global radius_b1
	global theta_b1
	global fi_b1 
	global radius_b2
	global theta_b2
	global fi_b2

	i = i + 1

	if i > 100:
		i = 0
		pose_msg = data.pose[1]
		(r, p, y) = tf.transformations.euler_from_quaternion([pose_msg.orientation.x, pose_msg.orientation.y,
			 pose_msg.orientation.z, pose_msg.orientation.w])


			 #Calculate sensor position as summ of base robot position
			 # and sensor position related to robot
		x_b1_fixed = pose_msg.position.x + radius_b1 * numpy.cos(fi_b1 + p) * numpy.cos(theta_b1 + y)
		y_b1_fixed = pose_msg.position.y + radius_b1 * numpy.sin(theta_b1 + y) * numpy.cos(fi_b1 + p)
		z_b1_fixed = pose_msg.position.z + radius_b1 * numpy.sin(fi_b1 + p)

		x_b2_fixed = pose_msg.position.x + radius_b2 * numpy.cos(fi_b2 + p) * numpy.cos(theta_b2 + y)
		y_b2_fixed = pose_msg.position.y + radius_b2 * numpy.sin(theta_b2 + y) * numpy.cos(fi_b2 + p)
		z_b2_fixed = pose_msg.position.z + radius_b2 * numpy.sin(fi_b2 + p)





		msg_to_sent.beacon_1.x = x_b1_fixed
		msg_to_sent.beacon_1.y = y_b1_fixed
		msg_to_sent.beacon_1.z = z_b1_fixed

		msg_to_sent.beacon_2.x = x_b2_fixed
		msg_to_sent.beacon_2.y = y_b2_fixed
		msg_to_sent.beacon_2.z = z_b2_fixed
		pub.publish(msg_to_sent)


#####################################################

i = 0

rospy.init_node('gps_sim')

pose_msg = Pose()
msg_to_sent = gps_data()

pub = rospy.Publisher('gps_pose', gps_data, queue_size=10)
rospy.Subscriber("/gazebo/model_states", ModelStates, callback)


rospy.spin()

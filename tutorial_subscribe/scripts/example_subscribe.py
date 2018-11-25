#!/usr/bin/python2

from __future__ import print_function

import rospy

import time

from tutorial_msg.msg import SingleNumber

def callback_number( message ):
	print( "==========================Listen number is " + str(message.firstNumber) )

if __name__=="__main__":
	rospy.init_node("subscribe_number_python")

	rospy.Subscriber("topic_number" , SingleNumber , callback_number , queue_size=6 
					, tcp_nodelay = True )
	
	limit_print = 10000000
	sleep_by_python = 0.5

	ros_rate = rospy.Rate( 10 )

	while( not rospy.is_shutdown() ):
		count = 0 
		print("Before Loop receive value========================")
		while( count < limit_print ):
			count += 1
		print("============================Before ros sleep")
		ros_rate.sleep()
		print("============================ros sleep wake up")



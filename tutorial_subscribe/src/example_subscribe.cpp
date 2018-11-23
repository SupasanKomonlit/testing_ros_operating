/*
	FILE		: example_subscribe.cpp
	PURPOSE		: For testing and study about characteristics of subscribe

	AUTHOR		: Supasan Komonlit
	CREATE ON	: 2018, NOV 22

	NAMESPACE	: None
	PACKAGE		: tutorial_subscribe
*/

#include	<ros/ros.h>

#include	<stdio.h>
#include	<iostream>

#include	<tutorial_msgs/SingleNumber.h>

void listen_number( const tutorial_msgs::SingleNumber message ){
	printf("    Listen_number : %ld\n" , message.firstNumber );
}

int main( int argc , char **argv ){

	// when you want to use ros library you must init node for entering ros system
	ros::init( argc , argv , "example_subscribe" );

	ros::NodeHandle nh("~");

	std::string topic_subscribe;
	int queqe_subscribe;
	double rate_subscribe;

	// set up about param prepare for use launch file to run this code
	nh.param< std::string >("example_topic" , topic_subscribe , "topic_number");
	nh.param< int >("example_queqe_subscribe" , queqe_subscribe , 2 );
	nh.param< double >("example_rate_subscribe" , rate_subscribe , 0.1 );

	// set up subscribe
	ros::Subscriber sub_number = nh.subscribe( topic_subscribe , 1 , &listen_number );
	
	ros::Rate rate( rate_subscribe );

	printf( "rate for subscribe is %lf\n" , rate_subscribe );

	while( ros::ok() ){
		printf("Before spinOnce\n");
		ros::spinOnce();
		printf("After spinOnce\n");
		rate.sleep();
	}

}

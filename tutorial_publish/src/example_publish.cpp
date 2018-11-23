/*
	FILE		:	example_publish.cpp	 
	PURPOSE		:	For testing and study about characterictics of publisher

	AUTHOR		:	Supasan Komonlit
	CREATE ON	:	2018, NOV 22

	NAMESPACE	:	None
	PACKAGE		:	tutorial_publish
*/

#include	<ros/ros.h>

#include	<stdio.h>
#include	<iostream>

#include	<tutorial_msgs/SingleNumber.h>

int main( int argc , char **argv ){

	//  test argument of main
	printf( "Value of argc %d\n" , argc );
	printf( "Value of argv %c\n" , argv );

	// when want to use ros library you must to init node for entering ros system
	ros::init( argc , argv , "example_publish" ); 

	// when want to use handle class from ros you must to have handle object for use that
	ros::NodeHandle nh("");

	std::string topic_publish;
	int queqe_publish;
	double rate_publish;
	int limit_value;

	nh.param< std::string >("example_topic" , topic_publish , "publish_number");
	nh.param< int >("example_queqe_publish" , queqe_publish , 10 );
	nh.param< double >("example_rate_publish" , rate_publish , 1 );
	nh.param< int >("example_value_publish" , limit_value , 1000000 );

	ros::Publisher test_publisher = nh.advertise< tutorial_msgs::SingleNumber >(
									topic_publish , queqe_publish
								);

	ros::Rate rate( rate_publish );

	tutorial_msgs::SingleNumber data_message;
	data_message.firstNumber = 0;

	printf( "Before in to loop send data\n" );
	while( ros::ok() && data_message.firstNumber < limit_value ){
		printf( "Value of data is " );
		data_message.firstNumber++;
		test_publisher.publish( data_message );
		printf( "%d\n" , data_message.firstNumber);
		rate.sleep();	
	}
	printf( "End of loop send data\n");

}

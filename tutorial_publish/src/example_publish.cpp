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

#include	<thread>
#include	<chrono>

#include	<tutorial_msgs/SingleNumber.h>

int main( int argc , char **argv ){

	//  test argument of main
	printf( "Value of argc %d\n" , argc );
	printf( "Value of argv %c\n" , argv );

	// when want to use ros library you must to init node for entering ros system
	ros::init( argc , argv , "example_publish" ); 

	// when want to use handle class from ros you must to have handle object for use that
	ros::NodeHandle nh;
	ros::NodeHandle ph("~");

	std::string topic_publish;
	int queqe_publish;
	double rate_publish;
	int limit_value;
	int round_before_send;
	int sleep_before_send;

	nh.param< std::string >("example_topic" , topic_publish , "topic_number");
	ph.param< int >("example_queqe_publish" , queqe_publish , 10 );
	ph.param< double >("example_rate_publish" , rate_publish , 1 );
	ph.param< int >("example_value_publish" , limit_value , 1000000 );
	ph.param< int >("example_round_publish" , round_before_send , 1 );
	ph.param< int >("example_sleep_publish" , sleep_before_send , 0 );

	ros::Publisher test_publisher = nh.advertise< tutorial_msgs::SingleNumber >(
									topic_publish , queqe_publish
								);

	ros::Rate rate( rate_publish );

	tutorial_msgs::SingleNumber data_message;
	data_message.firstNumber = 0;

	printf( "Our rate to publish is %lf\n" , rate_publish );
	printf( "Our queqe to publish is %ld\n" , queqe_publish );
	printf( "Our round to publish is %ld\n" , round_before_send );
	printf( "Our sleep to publish is %ld\n" , sleep_before_send );

	printf( "Before in to loop send data\n" );
	while( ros::ok() && data_message.firstNumber < limit_value ){
		printf( "Value of data is " );
		for( int count = 0 ; count < round_before_send ; count++ ){
			data_message.firstNumber++;
			test_publisher.publish( data_message );
			printf( "-> %d " , data_message.firstNumber);
		}
		printf("\n");
		std::this_thread::sleep_for( std::chrono::seconds( sleep_before_send ) );
		printf("Slepp by ros ---------> " );
		rate.sleep();	
		printf("Wake UP\n");
	}
	printf( "End of loop send data\n");

}

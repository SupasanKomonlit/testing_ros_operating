/*
	FILE		: matrix_boost.cpp	
	PURPOSE		: For learning about import boost and using Boost library for matrix

	AUTHOR		: Supasan Komonlit
	CREATE ON	: 2018, NOV 25

	NAMESPACE	: None
	PACKAGE		: tutorial_boost
*/

#include	<ros/ros.h> // must import when want to use library of ros

#include	<stdio.h> // include basic library of c
#include	<iostream> // include basic library of cpp

// below is import library from boost you can find how to access "cd /usr/include/boost"
#include	<boost/numeric/ublas/matrix.hpp> //include matrix have include all library this part

int main( int argc , char **argv ){

	printf("Welcome to test import library boost for using matrix\n");
	double array_target_state[6] = { 3.0 , 1.0 , -1 , 0 , 0 , 0};
	double array_current_state[6] = { 1.0 , 1.0 , -1 , 0 , 0 , 0};

	boost::numeric::ublas::matrix< double > target_state ( 6 , 1 );
	
	printf("I will try to show data of target_state matrix\n");
	printf("\trows   : %ld\n" , target_state.size1() );
	printf("\tcolumn : %ld\n" , target_state.size2() );

	printf("\tMember in target matrix : \n\t[\n" );
	for( int run_row = 0 ; run_row < target_state.size1() ; run_row++ ){
		printf("\t");
		for( int run_column = 0 ; run_column < target_state.size2() ; run_column++ ){
			target_state( run_row , run_column ) = array_target_state[run_row];
			printf("%8.3lf" , target_state( run_row , run_column ) );
		} 
		printf("\n");
	}
	printf("\t]\n");

	boost::numeric::ublas::matrix< double > current_state ( 6 , 1 );

	printf("\tMember in current matrix : \n\t[\n" );
	for( int run_row = 0 ; run_row < target_state.size1() ; run_row++ ){
		printf("\t");
		for( int run_column = 0 ; run_column < current_state.size2() ; run_column++ ){
			current_state( run_row , run_column ) = array_current_state[run_row];
			printf("%8.3lf" , current_state( run_row , run_column ) );
		} 
		printf("\n");
	}
	printf("\t]\n");

	boost::numeric::ublas::matrix< double > tran_pos ( 1 , 6);
	tran_pos = boost::numeric::ublas::trans( target_state );
	printf("\tMember in transpos target matrix : \n\t[\n" );
	for( int run_row = 0 ; run_row < tran_pos.size1() ; run_row++ ){
		printf("\t");
		for( int run_column = 0 ; run_column < tran_pos.size2() ; run_column++ ){
			printf("%8.3lf" , tran_pos( run_row , run_column ) );
		} 
		printf("\n");
	}
	printf("\t]\n");

	boost::numeric::ublas::matrix< double > result_matrix ( 6 , 6 );
	result_matrix = boost::numeric::ublas::prod( current_state , tran_pos );
	printf("\tMember in result matrix : \n\t[\n" );
	for( int run_row = 0 ; run_row < result_matrix.size1() ; run_row++ ){
		printf("\t");
		for( int run_column = 0 ; run_column < result_matrix.size2() ; run_column++ ){
			printf("%8.3lf" , result_matrix( run_row , run_column ) );
		} 
		printf("\n");
	}
	printf("\t]\n");

	
}

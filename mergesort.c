
/* Mergesort 
Authors: Alex Alvarez, Matt Saiki
Class: USD Comp 494
Date: October 2016
*/

// being includes
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>
#include "mergesortparallel.h"
#include <time.h>
// end includes

//Begin forward declare
void generateRandomValues();
//End forward declare



int* serial_array;
int* serial_array_temp;
int* parallel_array;
int* parallel_array_temp;
int thread_count;
long array_size;
int main ( int argc, char* argv[]){
	
	// enter in command line arguments in form for thread_count and array_size
	thread_count = atoi(argv[1]);
	array_size = atol(argv[2]);
	time_t time_of_day;
	time_of_day = time(NULL);
	// mallocing for array
	serial_array = malloc(sizeof(int)*array_size);
	serial_array_temp = malloc(sizeof(int)*array_size);
	parallel_array = malloc(sizeof(int)*array_size);
	parallel_array_temp = malloc(sizeof(int)*array_size);
	// end malloc
	srand((unsigned int)(time_of_day));
	generateRandomValues();
	int i;
	for( i = 0; i < array_size; i++){
	printf(" serial array: %d\n",serial_array[i]);
	printf(" serial_temp_array: %d\n",serial_array_temp[i]);
	}
}
// end main

// function that uses time and rand() to generate random integers into serial array and serial temp.
void generateRandomValues(){
	int i;
	for(i = 0; i < array_size;i++){
		int my_rand = 1 + rand()%1000;
		serial_array[i] = my_rand;
		serial_array_temp[i] = my_rand;
	}
}
//End

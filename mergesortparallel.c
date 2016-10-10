/*
Mergesort Parallel
Author: Alexander Alvarez, Matt Saiki
Date: October 10,2016
USD Comp494
Purpose: Purpose of project is to parallelize the mergesort algorithm and compare speedup, efficency, to that of normal mergesort
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>
#include "mergesortparallel.h"
#include <time.h>


//global variable declare
extern int* serial_array;
extern int* serial_array_temp;
extern int* parallel_array;
extern int* parallel_array_temp;
extern int thread_count;
extern long array_size;
extern pthread_t* thread_handler;
// end global variable declare

//forward declare
int intiliazeThreads(int thread_count);
//end forward declare

int* mergeSortParallel(){
}



void barrier(){
}




int findBreakPoint(){
}


// function returns 0 or 1 on success
int intiliazeThreads(int thread_count){
	
	for( int i = 1; i < thread_count; i++){
		int check = pthread_create(&thread_handler[i],NULL,mergeSortParallel,(void*) i);
		if(check !=0){
			return 1;
		}
	}
	return 0;
}






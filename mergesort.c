
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
int validateSort(int numElements);
void serialMergeSort(int low, int mid, int high);
void serialSort(int bottom, int top);
//End forward declare


// Global variable
int* serial_array;
int* serial_array_temp;
int* parallel_array;
int* parallel_array_temp;
int thread_count;
long array_size;
// end global variable

//Begin Main
int main ( int argc, char* argv[]){
	if(argc != 3){ printf(" Wrong number of arguments\n"); exit(0);}	
	// enter in command line arguments in form for thread_count and array_size
	thread_count = atoi(argv[1]);
	array_size = atol(argv[2]);
	if(thread_count < 0 || array_size < 0){ printf(" please enter valid argument size postive values only\n"); exit(0);}
	// end command line arguments
	
	time_t time_of_day;
	time_of_day = time(NULL);
	srand((unsigned int)(time_of_day));
	struct timeval tv1,tv2;	
	// mallocing for array with error checking
	serial_array = malloc(sizeof(int)*array_size);
	
	if(serial_array == NULL){
		printf(" malloc failed, program exit\n");
		exit(1);
	}

	serial_array_temp = malloc(sizeof(int)*array_size);
	
	if(serial_array_temp == NULL){
		printf(" malloc failed, program exit\n");
		exit(1);
	}

	parallel_array = malloc(sizeof(int)*array_size);
	
	if(parallel_array == NULL){
		printf(" malloc failed, program exit\n");
		exit(1);
	}

	parallel_array_temp = malloc(sizeof(int)*array_size);
	
	if(parallel_array_temp == NULL){
		printf(" malloc failed, program exit\n");
		exit(1);
	}
	// end malloc
	// fill array with randomvalues
	generateRandomValues();
	// performing serial sort
	gettimeofday(&tv1,NULL);	
	serialSort(0,array_size-1);
	gettimeofday(&tv2,NULL);
	
	int check = validateSort(array_size);
	if(check != 0){printf("sorting failed\n");}
	double serial_time = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec);	
	printf("SerialTime is:%f\n",serial_time);
	// freeing memory
	free(serial_array);
	free(serial_array_temp);
	free(parallel_array);
	free(parallel_array_temp);
	return 0;	
}
// End Main

// function that uses time and rand() to generate random integers into serial array and serial temp.
void generateRandomValues(){
	int i;
	for(i = 0; i < array_size;i++){
		int my_rand = 1 + rand()%1000;
		serial_array[i] = my_rand;
		serial_array_temp[i] = my_rand;
		parallel_array[i] = my_rand;
		parallel_array_temp[i] = my_rand;
	}
}
// End generateRandomValues

/*
 * This function takes in the lowest and highest index and partitions the array into two halves until there is only 1 element in the subarray, at which point it begins to merge the subarrays back until it merges the entire array.
 */
void serialSort(int bottom, int top){
        if(bottom < top){
                int mid;
                mid = (bottom + top)/2;
                serialSort(bottom, mid);
                serialSort(mid+1, top);
                serialMergeSort(bottom, mid, top);
        }
}
// end SerialSort


/*
 * This function sorts the array/subarray. It takes in the lowest, mid, and highest index of the array.
 * First it compares elements from the bottom half of the array with the top half and inserts the smaller element in the lowest index of the array.
 * Then, if the first half of the sorted array came from [low-mid], it copies the [mid+1-high] to the second half of the sorted array. And vice versa if first half of sorted array came from [mid+1-high]
 * Lastly, it copies the temp array back to the original array
 */
void serialMergeSort(int low, int mid, int high){
        int a, b, i, index;
        a = index = low;
        b = mid+1;
        while((a<=mid)&&(b<=high)){
                if(serial_array[a]<=serial_array[b]){
                        serial_array_temp[index] = serial_array[a];
                        a++;
                }
                else{
                        serial_array_temp[index] = serial_array[b];
                        b++;
                }
                index++;
        }
        if(a>mid){
                for(i=b; i<=high; i++){
                        serial_array_temp[index] = serial_array[i];
                        index++;
                }
        }
        else{
                for(i=a; i<=mid; i++){
                        serial_array_temp[index] = serial_array[i];
                        index++;
                }
        }
        for(i=low; i<=high; i++){
                serial_array[i] = serial_array_temp[i];
        }
}
// End SerialMergeSort

/*
 * This method takes in the total number of elements in the array.
 * Then it iterates through the array to check if it is sorted correctly.
 * Returns 1 if not sorted correctly and 0 if there are no errors.
 */
int validateSort(int numElements){
        int i, j;
        for(i=0; i<numElements; i++){
		if(serial_array[i] != serial_array_temp[i]){return 1;}
		for(j=i; j<numElements; j++){
			if(serial_array[i]>serial_array[j]){ return 1;}
                }
        }
        return 0;
}
//end validateSort
//End

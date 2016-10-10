#ifndef MERGESORTPARALLEL_H
#define MERGESORTPARALLEL_H

extern int* serial_array;
extern int* serial_array_temp;
extern int* parallel_array;
extern int* parallel_array_temp;
extern int thread_count;
extern long array_size;
extern pthread_t* thread_handler;
void serialSort(int bottom, int top);
void serialMergeSort(int low, int mid, int high);

#endif
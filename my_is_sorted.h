#ifndef MY_IS_SORTED_H
#define MY_IS_SORTED_H

#include "MyHeap.h"
#include <iostream>

//Checks if the array is sorted from least to greatest
template <typename T>
bool my_is_sorted(T arr[], int size)
{
  bool sorted = true;
  
  if(size == 0)
	return true;
  
  int i = 0;
  while(sorted && i < size-1){
	if(arr[i] > arr[i+1])
      sorted = false;
		  
    i++;  
  }	  
	
  return sorted;
}





#endif
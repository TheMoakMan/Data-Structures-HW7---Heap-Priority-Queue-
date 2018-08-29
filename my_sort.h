#ifndef MY_SORT_H
#define MY_SORT_H

#include "MyHeap.h"
#include <iostream>

//Sorts the array from least to greatest using the MyHeap operations
template <typename T>
void my_sort(T arr[], int size)
{
  if(size == 0)
	return;

  MyHeap<int> data(arr, size);
  
  for(int i = size-1; i >= 0; i--){
	arr[i] = data.top();
    data.pop();	
  }
  
  return;
}

#endif
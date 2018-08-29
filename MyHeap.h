#ifndef MYHEAP_H
#define MYHEAP_H

#include <iostream>
#include <stdexcept>

using std::cout;

class EmptyException: public std::exception
{
    public:
        virtual const char * what() const throw()
        {
            return "Queue is empty!";
        }
}; 

template<typename T>
class MyHeap
{
  private:
    T *m_data;
    int max_size;
    int data_size;
    bool is_sorted;
	
  public: 
    MyHeap();
	
    ~MyHeap();

    MyHeap(const T source_arr[], int size);
    
    MyHeap(const MyHeap<T> &source);	
	
	MyHeap<T> & operator=(const MyHeap  &source);
	
	T top(); 
	
	void pop();
	
    void push(T value);
	
    bool empty();
	
    int size();
	
	void reserve(int new_cap);
	
	void shrink_to_fit();
	
	int capacity();
	
	int parent(int pos);
	
	int lChild(int pos);
	
	int rChild(int pos);
	
	int largest_Child(int pos);
	
	void print();
};

template <typename T>
void swap(T & a, T & b)
{
  T temp = b;
  b = a;
  a = temp;  
}

#include "MyHeap.hpp"

#endif
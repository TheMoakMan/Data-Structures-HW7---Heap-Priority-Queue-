const int DEFAULT_MAX_SIZE = 1;
const int DEFAULT_DATA_SIZE = 0;
EmptyException MyExcpt;

template <typename T>
MyHeap<T>::MyHeap()
{
  max_size = DEFAULT_MAX_SIZE;
  data_size = DEFAULT_DATA_SIZE;
  m_data = new T[max_size];
}

template <typename T>	
MyHeap<T>::~MyHeap()
{
  delete[] m_data;
}

template <typename T>
MyHeap<T>::MyHeap(const T source_arr[], int size)
{
  //Reserve enough space
  data_size = 0;
  max_size = data_size * 2;
  
  m_data = new T[max_size];
  
  //Copy the array into the heap but sort the values as they are
  //placed in
  for(int i = 0; i < size; i++){
    push(source_arr[i]); 
  }   
}

template <typename T>  
MyHeap<T>::MyHeap(const MyHeap<T> &source)
{
  //Copy the maximum size of the source
  max_size = source.max_size;
  
  //Create an array to be copied into
  m_data = new T[max_size];
  
  //Copy the data size of the source
  data_size = source.data_size;
  
  //Assign each element
  for(int i = 0; i < data_size; i++){
	m_data[i] = source.m_data[i];  
  }		
}	

template <typename T>	
MyHeap<T> & MyHeap<T>::operator=(const MyHeap<T>  &source)
{
  //Check if this is not the same object as source
  if(this == &source)
	return *this;
  
  //Clear the current heap before assigning
  delete[] m_data;
  
  //Copy the maximum size of the source vector
  max_size = source.max_size;
  
  //Create a new array to be copied into
  m_data = new T[max_size];
  
  //Copy the data size of the source vector
  data_size = source.data_size;
  
  //Assign each element
  for(int i = 0; i < data_size; i++){
	m_data[i] = source.m_data[i];  
  }
  
  return *this;		
}

template <typename T>	
T MyHeap<T>::top()
{
  if(empty())
	throw MyExcpt;

  return m_data[0];
} 

template <typename T>	
void MyHeap<T>::pop()
{
  //Prevent popping an empty container
  if(empty())
	return;

  //Remove root and move end to root
  m_data[0] = m_data[data_size - 1]; 
  data_size--;
  
  is_sorted = false;
  int temp_pos = 0;
  
  //Sort the root until it's in a proper place
  while(!is_sorted){
	int pos_Child = largest_Child(temp_pos);
	if(pos_Child == -1){
	  is_sorted = true;
	}
	else if(m_data[temp_pos] < m_data[pos_Child]){
      swap(m_data[temp_pos], m_data[pos_Child]);
	  temp_pos = pos_Child;
	}
	else
	 is_sorted = true;
  }

  if(data_size < (max_size / 4))
	shrink_to_fit();
}

template <typename T>	
void MyHeap<T>::push(T value)
{
  //Push the data on to the heap but sort it as it is placed in
  if(!(data_size < max_size))
    reserve(max_size * 2);	
	
  //Sort at insert	
  m_data[data_size] = value;
  int temp_pos = data_size++;
  while(temp_pos != 0 && m_data[temp_pos] > m_data[parent(temp_pos)]){
	int temp_pos_2 = parent(temp_pos);
	swap(m_data[temp_pos], m_data[temp_pos_2]);
	temp_pos = temp_pos_2;
  }
  
  if(data_size < (max_size / 4))
	shrink_to_fit();
}

template <typename T>	
bool MyHeap<T>::empty()
{
  if(data_size == 0)
    return true;

  return false;
}

template <typename T>	
int MyHeap<T>::size()
{
  return data_size;
}

template <typename T>	
void MyHeap<T>::reserve(int new_cap)
{
  max_size = new_cap;
  
  //Increase the array to the size of the new_cap.
  T * tempArray = new T[max_size];
  
  //Copy the old array into a temp one.
  for(int i = 0; i < data_size; i++){
  	tempArray[i] = m_data[i];
  }
	
  //Delete the old array.
  delete[] m_data;
	
  //Set the new array equal to the temp
  m_data = tempArray;	
}

template <typename T>	
void MyHeap<T>::shrink_to_fit()
{
  max_size = data_size * 2;
  
  //Shrink the array to twice the size of the data size.
  T * tempArray = new T[max_size];
  
  //Copy the old array into a temp one.
  for(int i = 0; i < data_size; i++){
  	tempArray[i] = m_data[i];
  }
	
  //Delete the old array.
  delete[] m_data;
	
  //Set the new array equal to the temp
  m_data = tempArray;
}

template <typename T>	
int MyHeap<T>::capacity()
{
  return max_size;
}

template <typename T>
int MyHeap<T>::parent(int pos)
{
  if(pos == 0)
	return 0;
 
  return (pos-1)/2;
}

template <typename T>
int MyHeap<T>::lChild(int pos)
{
  int cPos = (2 * pos) + 1;
  
  if(!(cPos < data_size)){
	return -1;
  }
  
  return cPos; 
}

template <typename T>
int MyHeap<T>::rChild(int pos)
{
  int cPos = (2 * pos) + 2;
  
  if(!(cPos < data_size)){
	return -1;
  }

  return cPos;	
}

template <typename T>
int MyHeap<T>::largest_Child(int pos)
{
  int lPos = lChild(pos);
  int rPos = rChild(pos);
  
  //If there is no left child, there are no children	
  if(lPos == -1){
	return -1;
  }

  if(m_data[lPos] > m_data[rPos]){
   return lPos;
  }
  else{
   return rPos;
  }   
}

template <typename T>
void MyHeap<T>::print()
{
  cout << "[";
  for(int i = 0; i < data_size; i++){
	cout << m_data[i] << ", ";    
  }
  cout << "]";
	
  return;	
}
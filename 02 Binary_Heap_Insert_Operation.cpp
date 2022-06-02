//we are implementing MIN heap
//in MIN heap...the parent is smaller than its children

//time complexity of insert operation in MIN heap = O(log N)...because we travel along the height of the complete binary tree
//the *complete binary tree* is just for visualization...actually no's are stored in an array


#include <bits/stdc++.h> 
using namespace std; 

class MinHeap{
    int *arr;
    int size;
    int capacity;
    
    public:
    
    MinHeap(int c){
    size = 0; 
    capacity = c; 
    arr = new int[c];
    }

    int left(int i) { return (2*i + 1); } 
    int right(int i) { return (2*i + 2); } 
    int parent(int i) { return (i-1)/2; } 
    
    void insert(int x) 
    { 
      if (size == capacity)
        return; //in case the capacity is reached
      size++; 
      arr[size-1]=x; //assign the element in the last lvl and leftmost

      for (int i=size-1; i!=0 && arr[parent(i)]>arr[i]; ) 
      { 
         swap(arr[i], arr[parent(i)]); //if the inserted element is smaller than its parent, then swap them....stop its smaller than its parent OR it becomes the root of the binary tree/min heap
         i = parent(i); 
      } 
    }
    
};

int main() 
{ 
    MinHeap h(11);
    h.insert(3); 
    h.insert(2);
    h.insert(15);
    h.insert(20);
    return 0;
} 

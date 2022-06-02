// Given an array of N elements. The task is to build a Binary Heap from the given array. The heap can be either Max Heap or Min Heap.

// Simple Approach: 
// Suppose, we need to build a Max-Heap from the array elements. 
// So, the idea is to heapify the complete binary tree formed from the array in reverse level order following a top-down approach.
// That is first heapify, the last node in level order traversal of the tree, then heapify the second last node and so on. 
// Time Complexity: Heapify a single node takes O(log N) time complexity where N is the total number of Nodes. 
// Therefore, building the entire Heap will take N heapify operations and the total time complexity will be O(N*logN).
// In reality, building a heap takes O(n) time depending on the implementation which can be seen here.
    
// Optimized Approach: 
// The above approach can be optimized by observing the fact that the leaf nodes need not to be heapified as they already follow the heap property. 
// Also, the array representation of the complete binary tree contains the level order traversal of the tree.
// So the idea is to find the position of the last non-leaf node and perform the heapify operation of each non-leaf node in reverse level order. 


//in simple words: do this->
//  for(int i=(size-2)/2;i>=0;i--) 
//             minHeapify(i);


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
    
    void minHeapify(int i) 
    { 
        int lt = left(i); 
        int rt = right(i); 
        int smallest = i; 
        if (lt < size && arr[lt] < arr[i]) 
            smallest = lt; 
        if (rt < size && arr[rt] < arr[smallest]) 
            smallest = rt; 
        if (smallest != i) 
        { 
            swap(arr[i],arr[smallest]); 
            minHeapify(smallest); 
        } 
    }
    
    void buildHeap(){
        for(int i=(size-2)/2;i>=0;i--) //position of the last non-leaf node is (size-2)/2...always
            minHeapify(i);
    }
    
};

int main() 
{ 
    MinHeap h(11);
    return 0;
} 

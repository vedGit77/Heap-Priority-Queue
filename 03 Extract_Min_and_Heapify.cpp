// Min-Heapify does this: Given a binary heap with 1 possible violation, fix the binary heap

//now forget if theres a voilation in the binary heap and think for getMin() and extractMin() functions:
//1. getMin(): simply returns arr[0]...minimum most element in min heap
//2. extractMin():REMOVES the minimum element from MinHeap. 
//               :so basically it swaps the min element (arr[0]) with the last element(arr[n-1]...NOT surely largest)
//               :then it decreases size...(size--)....and applies min-heapify to arr (with 1 size smaller)
//               :so now our remaining heap is fixed
//               :Time Complexity of this Operation is O(Logn) as this operation needs to maintain the heap property (by calling heapify()) after removing root.
  

//in this code...we will discuss extractMin()...ie given a binary heap, extract the smallest element and fix the remaining heap...
//now obvio...extractMin will use minHeapify to fix the remining heap


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
        if (size == capacity)return;
        size++; 
        arr[size-1]=x; 

        for (int i=size-1;i!=0 && arr[parent(i)]>arr[i];) 
        { 
           swap(arr[i], arr[parent(i)]); 
           i = parent(i); 
        } 
    }
    
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
    
    int extractMin() 
    { 
        if (size <= 0) 
            return INT_MAX; 
        if (size == 1) 
        { 
            size--; 
            return arr[0]; 
        }  
        swap(arr[0],arr[size-1]);
        size--; 
        minHeapify(0); 

        return arr[size]; 
    } 
    
};

int main() 
{ 
    MinHeap h(11);
    h.insert(3); 
    h.insert(2);
    h.insert(15);
    h.insert(20);
    cout << h.extractMin() << " ";
    return 0;
} 

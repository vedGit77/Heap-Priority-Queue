// Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time. 
// For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.

// Approach: SUPER SIMPLE!
// We will make a priority queue using MIN heap of size k....so that top element returns the minimum element
// we will remove the 1st element, and add the last+1 in the queue...say priority queue was from (i to i+k-1), now remove the 1st element, and add the (i+k)th element....continue this...
// this will return us a sorted array



#include <bits/stdc++.h> 
using namespace std; 

int sortK(int arr[], int n, int k) 
{ 
    priority_queue<int, vector<int>, greater<int>> pq; //pq using MIN heap!
    
    for(int i=0;i<=k;i++) //time for thsi loop = O(K*log K)
        pq.push(arr[i]);
        
    int index = 0; 
    for (int i = k + 1; i < n; i++) //time for this loop = O((n-K)*log K)
    { 
      arr[index++] = pq.top(); 
      pq.pop(); 
      pq.push(arr[i]); 
    } 
    
    //once we have no more elements to add, but we still have to pop...that time this while loop comes into play
    while (pq.empty() == false) //time for thsi loop = O(K*log K)
    { 
      arr[index++] = pq.top(); 
      pq.pop(); 
    } 
} 

void printArray(int arr[], int size) 
{ 
    for (int i = 0; i < size; i++) 
      cout << arr[i] << " "; 
    cout << endl; 
} 
 
int main() 
{ 
    int k = 3; 
    int arr[] = { 2, 6, 3, 12, 56, 8 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    sortK(arr, n, k); 

    cout << "Following is sorted array" << endl; 
    printArray(arr, n); 

    return 0; 
} 

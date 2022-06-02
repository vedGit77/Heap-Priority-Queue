// Method 1: simply sort...time O(n log n)

//Method 2: use max heap...priority queue...time = O(N + k*log N)....N for building the max heap, and K*logN for extracting the K greatest elements

//Method 3: using min heap...priority queue...time = O(K + (N-K)*log K)

#include <bits/stdc++.h>
using namespace std;

void firstKElements(int arr[], int n, int k)
{
    priority_queue <int,vector<int>,greater<int>> minHeap; //min heap
    for(int i = 0; i < k; i++)  //initially, build a min heap of first k elements
    {
        minHeap.push(arr[i]);
    }
    for(int i = k; i < n; i++)  //no iterate from k index till the end
    {                             
        if (minHeap.top() > arr[i])  //if the current element is smaller than the smallest element in min heap
            continue;
        else   //if the current element is greater than the smallest element in min heap
        {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }

    while(minHeap.empty()==false)
    {
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }
}

int main()
{

	int arr[] = { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	int k = 3;

	firstKElements(arr,size,k);

	return 0;
}

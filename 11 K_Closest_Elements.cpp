//Question: We are given an array, a number k, and a number x....we need to find the k closest elements to the number x 
//eg. arr[] = {30,40,32,33,36,37} , k=3 and x=38.....and is : 37 36 40 

// Approach explained with code

//Time: O(N*log K)


#include <bits/stdc++.h>
using namespace std;

void printKClosest(int arr[], int n, int k, int x)
{
    priority_queue<pair<int, int> > pq; //max heap...each element is a pair...the pair is {abs(arr[i]-x) , i}
    for (int i = 0; i < k; i++) //push for the first k elements
        pq.push({ abs(arr[i] - x), i }); 
  
    for (int i = k; i < n; i++) //for k to n-1 index
    { 
        int diff = abs(arr[i] - x); 
        if (pq.top().first > diff)  // if diff is lesser than pq.top().first...it means that the element is closer...so pop() (the top element has greatest difference as compared to the other k-1 elements in the priority queue...thats why it was on the top) and insert the new one
        {
            pq.pop(); 
            pq.push({ diff, i }); 
        }
    } 
   
    while (pq.empty() == false) 
    { 
        cout << arr[pq.top().second] << " "; 
        pq.pop(); 
    } 
}

int main()
{

	int arr[] = { 10,30,5,40,38,80,70 };

	int size = sizeof(arr) / sizeof(arr[0]);

	int x=35; int k = 3;

	printKClosest(arr,size,k,x);

	return 0;
}

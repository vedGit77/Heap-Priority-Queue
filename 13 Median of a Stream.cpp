//Remember...Median is always on a SORTED array

// Question:
//Given an input stream of N integers. 
//The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.
//eg. the given array/stream is: {25,7,10,15,20}, then O/P is {25,16,10,12.5,15}


//Naive sol: say given array size =n
//	   : so for i=1 till i=n, create array of size = i
//         : sort the array....now simply get median of the array, and print/store it
//         : so we continue this for all i's from 1 to n
//	   : Time= O(n*n) = O(n^2)



//Efficient soln: Time= O(n* log n)

// 1. Create two heaps. One max heap to maintain elements of lower half and one min heap to maintain elements of higher half at any point of time..
// 2. Take initial value of median as 0.
// 3. For every newly read element, insert it into either max heap or min-heap and calculate the median based on the following conditions: 
// a. If the size of max heap is greater than the size of min-heap and the element is less than the previous median 
//    then pop the top element from max heap and insert into min-heap and insert the new element to max heap else insert the new element to min-heap. 
//    Calculate the new median as the average of top of elements of both max and min heap.
// b. If the size of max heap is less than the size of min-heap and the element is greater than the previous median 
//    then pop the top element from min-heap and insert into the max heap and insert the new element to min heap 
//    else insert the new element to the max heap. Calculate the new median as the average of top of elements of both max and min heap.
// c. If the size of both heaps is the same. Then check if the current is less than the previous median or not. 
//    If the current element is less than the previous median then insert it to the max heap and a new median will be equal to the top element of max heap. 
//    If the current element is greater than the previous median then insert it to min-heap and new median will be equal to the top element of min heap.



#include <bits/stdc++.h>
using namespace std;

void printMedians(int arr[],int n){
    priority_queue<int> s;
    priority_queue<int, vector<int>,greater<int>> g;
    s.push(arr[0]);
    cout<<arr[0]<<" ";
  
    for(int i=1;i<n;i++)
    {
        int x=arr[i];
        if(s.size()>g.size())
        {
            if(s.top()>x)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
          else 
              g.push(x);
          cout<<(s.top()+g.top())/2.0<<" ";
        }
        else
        {
            if(x<=s.top())
            {
                s.push(x);
            }
            else
            {
                g.push(x);
                s.push(g.top());
                g.pop();
            }
            cout<<s.top()<<" ";
        }
    }
}

int main()
{
	int keys[] = { 12, 15, 10, 5, 8, 7, 16};
    
    printMedians(keys,7);
	
	return 0;
}

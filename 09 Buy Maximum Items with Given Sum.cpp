//basically we are given a cost array, and a variable sum.
//we have to tell the max items we can buy. (basically sum is our budget)

//Method 1: Simply sort and check from the starting elements...
//        : when value of top element(ie. a[i]) <= sum....do count++, and sum-=arr[i]...repeat this....
//        : time O(N*log N)

//Method 2: Use priority queue using MIN heap....so that the starting element is the smallest
//        : next is the same logic as method 1
// time complexity = O(res*log N)....where res is the no. of times we popped the front element....res < N....thus better than method 1


#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    int n=5;
    int cost[n]={1,12,5,111,200};
    int sum=10;
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    int res=0;
    for(int i=0;i<n;i++) // time for this loop = O(n*log n)...but...
        pq.push(cost[i]);//could be improvised if we did-> priority_queue<int,vector<int>,greater<int>> pq(cost,cost+5)...in that case time for initialization = O(N)
    
    for(int i=0;i<n;i++)//time for this loop = O(res*log N)....since time for pop() is O(log N)...and we popped res times 
    {
        if(pq.top()<=sum)
        {
            sum-=pq.top();
            pq.pop();
            res++;
        }
        else
            break;
    }
    cout<<res;
    return 0;
} 

// Priority queue basically uses MAX heap data structure
//we can alter it to work on min heap too

// .push() function pushes an element into the priority queue...basically uses the insert in heap...see 02 file
// .top() returns the topmost element....ie ALWAYS THE LARGEST ELEMENT
// .pop() deletes the topmost element...checkout for delete in 04 file
// .size() returns the number of elements in the priority queue

//if we implement using MIN heap...then .top() would display the SMALLEST element 
// priority_queue <int,vector<int>,greater<int>> pq; ....this way for operation using MIN heap
//the above line syntax is a bit wierd.....vector<int> extra aaya hai....usually there is only <int,greater<int>>...so remember this anomaly!

#include <iostream>
#include<queue>
using namespace std;

int main(){
    //2 ways to make
    priority_queue <int> pq;//way 1: using MAX heap
    priority_queue <int,vector<int>,greater<int>> pq; //way 2: using MIN heap
    
    //3 ways to push
    pq.push(10);//way 1: simply push...this is like insert in a binary heap...so to insert n elements...time = O(N*logN)...O(logN) for each element
    pq.push(15);
    pq.push(5);
    
    int arr[]={10,5,15}
    priority_queue<int>pq(arr,arr+3);//way 2: pq(begin iterator , end iterator + 1)...way 2&3 better than way 1...as it uses Build heap function...O(N) total time
    
    vector<int>v = {10,5,15};
    priority_queue<int>pq(v.begin(),v.end());//way 3: pq(begin iterator , end iterator +1)
    
    
    cout<<pq.size()<<" ";
    cout<<pq.top()<<" ";
    while(pq.empty()==false)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    
    return 0;
}

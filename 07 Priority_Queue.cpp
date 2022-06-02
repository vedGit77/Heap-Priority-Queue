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
    priority_queue <int> pq;
//     priority_queue <int,vector<int>,greater<int>> pq;   // do this way for applying using min heap
    pq.push(10);
    pq.push(15);
    pq.push(5);
    cout<<pq.size()<<" ";
    cout<<pq.top()<<" ";
    while(pq.empty()==false)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    
    return 0;
}

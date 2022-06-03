// Super Naive Soln: combine all the k arrays into 1 array...apply sort
// 		   : Time = O(nk * log nk)....where n = no. of elements in each array(upperbound)....and k = no. of arrays

//Naive Soln: create an empty array(say array name is ved) of size = total no. of elements in all the arrays combined 
//          : fill the 1st array into ved
//	    : now from the second array till the last array....keep adding each array to ved, and apply merge function of the merge sort after adding each array
//          : Time = O(n +2n +3n + 4n...kn) = O(n*k*k) OR O(nk^2)


//Efficient Approach: Use min heap (priority queue pq)
//		    : the pq is of type triplet (triplet is made using a struct)...triplet has value of the element(val), posn of that element in the array(vPos), and position of the array in the k sorted arrays(aPos)
//		    : approach explained with code
//		    : Time = O(n*k*log k)...since total n*k elements...and height of the min heap is log k



#include <bits/stdc++.h>
using namespace std;

struct Triplet{
    int val,aPos,vPos;
    Triplet(int v,int ap, int vp)
    {
        val=v;aPos=ap;vPos=vp;
    }
};

struct MyComp{
    bool operator()(Triplet &t1,Triplet &t2)
    {
        return t1.val>t2.val;
    }
};

vector<int> mergeArr(vector<vector<int> > &arr) 
{ 
    vector<int> res; 
      
    priority_queue <Triplet, vector<Triplet>,MyComp> pq;
    
    for(int i=0;i<arr.size();i++)  //the min heap will be of size = k....initially containing the smallest element from each array
    {
        Triplet t(arr[i][0],i,0);
        pq.push(t);
    }
    
    while(pq.empty()==false)
    {
        Triplet curr=pq.top();  //remove the topmost element(smallest in min heap)....we did the extractMin function here...see 03 file
        pq.pop();
        res.push_back(curr.val);
        int ap=curr.aPos; 
	int vp=curr.vPos;
        if(vp+1< arr[ap].size())//take care if there are no more elements in the array
        {
            Triplet t(arr[ap][vp+1],ap,vp+1); // push the next element of the array from which the curr element was removed
            pq.push(t);
        }
    }

    return res;
}

int main()
{

	vector<vector<int> > arr{ { 10, 20, 30 }, 
                              { 5, 15 }, 
                              { 1, 9, 11, 18 } }; 
  
    vector<int> res=mergeArr(arr);  
    cout << "Merged array is " << endl; 
    for (auto x : res) 
        cout << x << " "; 
  
    return 0; 
}

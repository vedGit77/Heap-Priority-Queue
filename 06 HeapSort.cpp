//Modification of selection sort
//Time: O(N*log N)
//UN-stable algo

//here we use MAX-HEAP...since we want in ascending

//for descending...use MIN-HEAP

#include <iostream> 
using namespace std; 


void heapify(int arr[], int n, int i) 
{ 
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) 
      largest = l; 

    if (r < n && arr[r] > arr[largest]) 
      largest = r; 

    if (largest != i) 
    { 
      swap(arr[i], arr[largest]); 
      heapify(arr, n, largest); 
    } 
} 

void buildheap(int arr[],int n){
    for (int i = (n-2)/2 ; i >= 0; i--) //i have already explained the reason for (n-2)/2
	heapify(arr, n, i);
}
void heapSort(int arr[], int n) 
{  
    buildheap(arr,n); //first build a heap 

    for (int i=n-1; i>0; i--) 
    { 
      swap(arr[0], arr[i]);//basically arr[0] will be the max element bw 0 and i...swapping means we have sorted the array from i to n-1
      heapify(arr, i, 0); //heapify for arr[0] to arr[i-1] and repeat....
    } 
} 

void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
      cout << arr[i] << " "; 
    cout << "\n"; 
} 
 
int main() 
{ 
	int arr[] = {12, 11, 13, 5, 6, 7}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	heapSort(arr, n); 

	cout << "Sorted array is \n"; 
	printArray(arr, n); 
} 

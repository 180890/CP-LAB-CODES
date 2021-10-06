/* C++ implementation of QuickSort for vector pair */
#include <iostream> 
#include<vector>
#include<string>

using namespace std; 
bool sortbysec( pair<string,int> &a,
               pair<string,int> &b)
{
    if (a.second < b.second)
    {
        return true;
    }
    else if (a.second == b.second)
    {
        if(a.first < b.first)
            return true;
        else 
            return false;
    }
    else 
    return false;
}
void swap(pair <string,int>& a, pair <string,int>& b) 
{ 
    pair <string,int> t;
    t.first=a.first;
    t.second=a.second;
    a.first=b.first;
    a.second=b.second;
    b.first=t.first;
    b.second= t.second;
} 

int partition (vector< pair <string,int> >& arr, int low, int high) 
{ 
	pair <string,int> pivot = arr[high-1]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <high; j++) 
	{ 
		// If current element is smaller than the pivot 
		if (sortbysec(arr[j] ,pivot) )
		{ 
			i++; // increment index of smaller element 
			swap(arr[i], arr[j]); 
		} 
	} 
	swap(arr[i + 1], arr[high-1]); 
	return (i + 1); 
} 


void quicksort(vector< pair <string,int> >& arr, int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high); 
		quicksort(arr, low, pi - 1); 
		quicksort(arr, pi + 1, high); 
	} 
} 

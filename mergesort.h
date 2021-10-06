/*Mergesort for vector pair*/
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
void merge( vector< pair <string,int> >& arr, int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	/* create temp arrays */
	vector<pair<string,int>>L;
	vector<pair<string,int>>R; 

	/* Copy data to temp  L and R */
	for (i = 0; i < n1; i++)
	{
	    L.push_back(make_pair(arr[l+i].first , arr[l+i].second));
		
	}
	for (j = 0; j < n2; j++) 
	{
		R.push_back(make_pair(arr[m + 1+ j].first , arr[m + 1+ j].second));
	}

	/* Merge the temp  back into arr[l..r]*/
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) 
	{ 
		if (sortbysec(L[i] , R[j]) )
		{ 
			arr[k].first = L[i].first; 
			arr[k].second = L[i].second;
			i++; 
		} 
		else
		{ 
			arr[k].first = R[j].first; 
			arr[k].second = R[j].second; 
			j++; 
		} 
		k++; 
	} 

	/* Copy the remaining elements of L[], if there 
	are any */
	while (i < n1) 
	{ 
		arr[k].first = L[i].first; 
			arr[k].second = L[i].second; 
		i++; 
		k++; 
	} 

	/* Copy the remaining elements of R[], if there 
	are any */
	while (j < n2) 
	{ 
		arr[k].first = R[j].first; 
			arr[k].second = R[j].second; 
		j++; 
		k++; 
	} 
} 
void mergesort(vector<pair<string,int>>& arr, int l, int r) 
{ 
	if (l < r) 
	{ 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l+(r-l)/2; 

		// Sort first and second halves 
		mergesort(arr, l, m); 
		mergesort(arr, m+1, r); 

		merge(arr, l, m, r); 
	} 
} 

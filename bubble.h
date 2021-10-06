/*bubble sort for vector pair*/
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
void bubblesort(vector<pair<string,int>>&arr,int l, int h)
{
    for(int i=0;i<h-1;i++)
    {
        for(int j=0;j<h-i-1;j++)
        {
            if(!(sortbysec(arr[j],arr[j+1])))
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

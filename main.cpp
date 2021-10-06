/*Geek went to a grocery shop with a bag in his hand, 
where he found there are two sections of products and he wanted to take P products from the first section and Q products from the second section.
As geek is greedy, he wanted to fill his bag such that he spends a lesser amount. 
If two products have the same price then geek chooses the lexicographically smaller named product.
Given N products with their prices of the first section and M products with their prices of the second section,
help the geek to choose those products. Print the names of the products in the order they have chosen*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include "quicksort.h"
using namespace std;

/* Driver program to test above functions */
int main() 
{ 
    int t;
	cin>>t;
	while(t--)
	{
	    int n,m,p,q;
	    cin>>n>>m>>p>>q;
	    vector< pair <string,int> > vect;
	    string s;
	    int cost;
	    for(int i=0;i<n;i++)
	    {
	        cin>>s;
	        cin>>cost;
	        vect.push_back(make_pair(s,cost));
	    }
	    vector< pair <string,int> > vect1;
	    for(int i=0;i<m;i++)
	    {
	        cin>>s;
	        cin>>cost;
	        vect1.push_back(make_pair(s,cost));
	    }
	   quicksort(vect,0, n);
	   quicksort(vect1,0, n);
	   cout<<vect[0].second<<vect[1].second<<vect[2].second;
	   cout<<endl;
	   cout<<vect1[0].second<<vect1[1].second<<vect1[2].second;
	   cout<<endl;
	    int i=0;
	    int j=0;
	    while(i<p && j<q)
	    {
	        if(vect[i].second < vect1[j].second)
	        {
	            cout<<vect[i].first<<" ";
	            i++;
	        }
	       else if(vect1[j].second< vect[i].second)
	            {   cout<<vect1[j].first<<" ";
	                j++;
	            }
	       else if(vect[i].second == vect1[j].second)
	       {
	           if(vect[i].first < vect1[j].first)
	            {
	            cout<<vect[i].first<<" ";
	            i++;
	            }
	            else
	            {
	            cout<<vect1[j].first<<" ";
	            j++;
	            }
	       }
	      
	  
	    }
	    if(j<q)
	    {
	        for(int i=j;i<q;i++)
	        {   
	            
	           cout<<vect1[i].first<<" ";
	        }
	    }
	    if(i<p)
	    {
	        for(int k=i;k<p;k++)
	        {   
	            
	           cout<<vect[k].first<<" ";
	        }
	    }
	    cout<<endl;
	}
	
	
	return 0;
} 


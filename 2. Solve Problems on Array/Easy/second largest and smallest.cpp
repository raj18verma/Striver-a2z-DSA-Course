// Problem Link:- https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<bits/stdc++.h>
using namespace std;

int secondLargest(int n,vector<int>&a)
{
    int largest=a[0];
    int sLargest=-1;
    for(int i=1 ; i<n ; i++)
    {
        if(a[i]>largest)
        {
            sLargest=largest;
            largest=a[i];\
        }
        else if(a[i]>sLargest && a[i]<largest)
        sLargest=a[i];
    }
    return sLargest;
}
int secondSmallest(int n,vector<int>&a)
{
    int smallest=a[0];
    int sSmallest=INT_MAX;
    for(int i=1 ; i<n ; i++)
    {
        if(a[i]<smallest)
        {
           sSmallest=smallest;
            smallest=a[i];
        }
        else if(a[i]!=smallest && a[i]<sSmallest)
        sSmallest=a[i];
    }
    return sSmallest;
}
vector<int> getSecondOrderElements(int n, vector<int> a)
 {
    int largest=secondLargest(n,a);
    int smallest=secondSmallest(n,a);
    return {largest,smallest};

}

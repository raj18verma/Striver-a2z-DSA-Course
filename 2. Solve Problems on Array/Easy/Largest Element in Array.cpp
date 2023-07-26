// Problem Link:- https://www.codingninjas.com/studio/problems/largest-element-in-the-array-largest-element-in-the-array_5026279?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int maxelement=INT_MIN;
    for (int i=0; i<n; i++){
        if(arr[i]>maxelement)
        maxelement=arr[i];
    }
    return maxelement;
}

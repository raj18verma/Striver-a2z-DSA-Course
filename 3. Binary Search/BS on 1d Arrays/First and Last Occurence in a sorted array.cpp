// BRUTEFORCE APPROACH 

/*
1. As the array is already sorted, start traversing the array from the back using a for loop and check whether the element is present or not.
2. If the target element is present, break out of the loop and print the resulting index.
3. If the target element is not present inside the array, then print -1                   */

int solve(int n, int key, vector < int > & v) {
  int res = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (v[i] == key) {
      res = i;
      break;
    }
  }
  return res;
}

// Time Complexity: O(n) 
// Space Complexity: O(1) not considering the given array



// Better Approach (using Upper Bound and Lower Bound)

#include <bits/stdc++.h> 

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int upperBound(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int lb=lowerBound(arr, n, k);
    if(lb==n || arr[lb]!=k) return {-1,-1};
    int up=upperBound(arr, n, k);
    return {lb,up-1};
}

// Time Complexity:- 2*O(logN)
// Space Complexity:- O(1)


// Optimal Approach (using Binary Search)

#include <bits/stdc++.h> 

int firstOccurence(vector<int> &arr, int n, int k){
    int low=0, high=n-1;
    int first=-1;

    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k){
            first=mid;
            high=mid-1;
        }
        else if(arr[mid]<k) low=mid+1;
        else high=mid-1;
    }
    return first;
}

int lastOccurence(vector<int> &arr, int n, int k){
    int low=0, high=n-1;
    int last=-1;

    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k){
            last=mid;
            low=mid+1;
        }
        else if(arr[mid]<k) low=mid+1;
        else high=mid-1;
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int first=firstOccurence(arr, n, k);
    if(first==-1) return {-1,-1};
    int last=lastOccurence(arr,n,k);
    return {first,last};
}

// Time Complexity:- 2*O(logN)
// Space Complexity:- O(1)

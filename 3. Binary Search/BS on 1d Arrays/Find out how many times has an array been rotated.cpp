// Bruteforce Approach 

//INTUITION:
/* 
(i) First, we will declare an ‘ans’ and an ‘index’ variable initialized with a large number and -1 respectively.
(ii) Next, we will iterate through the array and compare each element with the variable called ‘ans’. Whenever we encounter an element ‘arr[i]’ that is smaller than ‘ans’, we will update ‘ans’ with the value of ‘arr[i]’ and also update the ‘index’ variable with the corresponding index value, ‘i’.
(iii) Finally, we will return ‘index’ as our answer.   */

int findKRotation(vector<int> &arr) {
    int n = arr.size(); //size of array.
    int ans = INT_MAX, index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < ans) {
            ans = arr[i];
            index = i;
        }
    }
    return index;
}

// Time Complexity:-  O(N), N = size of the given array. Reason: We have to iterate through the entire array to check if the target is present in the array.
// Space Complexity: O(1) Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).




// Optimal Approach:

// INTUITION: Return the index of the minimum element in sorted Array.

#include<bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr){
    // Write your code here.   
    int n=arr.size();
    int low=0, high=n-1;
    int ans = INT_MAX;
    int index=-1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            if(arr[low]<ans){
                index=low;
                ans=arr[low];
            }
            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:
            // keep the minimum:

            // Eliminate right half:
            high = mid - 1;
            if(arr[mid]<ans){
                index=mid;
                ans=arr[mid];
            }
            index=mid;
        }
    }
    return index; 
}


// Time Complexity:  O(logN), N = size of the given array. Reason: We are basically using binary search to find the minimum.
// Space Complexity: O(1) Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).


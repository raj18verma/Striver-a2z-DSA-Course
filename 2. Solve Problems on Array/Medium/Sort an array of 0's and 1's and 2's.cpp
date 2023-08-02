// Bruteforce Approach (SORT inbuilt function)

//Intuition: Sorting ( even if it is not the expected solution here but it can be considered as one of the approaches). Since the array contains only 3 integers, 0, 1, and 2. Simply sorting the array would arrange the elements in increasing order.
// T.C :- O(N*logN)
// S.C :- O(1)


// Better Approach (Keeping count of the values)

//Intuition: Since in this case there are only 3 distinct values in the array so it’s easy to maintain the count of all, Like the count of 0, 1, and 2. This can be followed by overwriting the array based on the frequency(count) of the values.

#include <bits/stdc++.h> 
void sortArray(vector<int>& arr, int n)
{
    // Write your code here
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) cnt0++;
        else if (arr[i] == 1) cnt1++;
        else cnt2++;
    }
    //Replace the places in the original array:
    for (int i = 0; i < cnt0; i++) arr[i] = 0; // replacing 0's
    for (int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1; // replacing 1's
    for (int i = cnt0 + cnt1; i < n; i++) arr[i] = 2; // replacing 2's
}

// T.C :- O(N) + O(N), where N = size of the array. First O(N) for counting the number of 0’s, 1’s, 2’s, and second O(N) for placing them correctly in the original array.
// S.C :- O(1) as we are not using any extra space.



// Optimal Approach (Dutch National Flag Algorithm)

//INTUITION :- This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules.  The rules are the following:
// arr[0….low-1] contains 0. [Extreme left part]
//arr[low….mid-1] contains 1.
//arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array
//The middle part i.e. arr[mid….high] is the unsorted segment.  


void sortArray(vector<int>& arr, int n) {

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}


// T.C :- O(N), where N = size of the given array. Reason: We are using a single loop that can run at most N times.
// S.C :- O(1) as we are not using any extra space.



// BRUTEFORCE (Linear Search)

//INTUITION:- A crucial observation to note is that if an element appears twice in a sequence, either the preceding or the subsequent element will also be the same. But only for the single element, this condition will not be satisfied. So, to check this the condition will be the following:
/* If arr[i] != arr[i-1] and arr[i] != arr[i+1]: If this condition is true for any element, arr[i], we can conclude this is the single element.
  
Edge Cases:

1. If n == 1: This means the array size is 1. If the array contains only one element, we will return that element only.
2. If i == 0: This means this is the very first element of the array. The only condition, we need to check is: arr[i] != arr[i+1].
3. If i == n-1: This means this is the last element of the array. The only condition, we need to check is: arr[i] != arr[i-1].
So, we will traverse the array and we will check for the above conditions.  */


int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.
    if (n == 1) return arr[0];

    for (int i = 0; i < n; i++) {

        //Check for first index:
        if (i == 0) {
            if (arr[i] != arr[i + 1])
                return arr[i];
        }
        //Check for last index:
        else if (i == n - 1) {
            if (arr[i] != arr[i - 1])
                return arr[i];
        }
        else {
            if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
                return arr[i];
        }
    }

    // dummy return statement:
    return -1;
}


// TIME COMPLEXITY:- O(N), N = size of the given array. Reason: We are traversing the entire array.
// Space Complexity: O(1) as we are not using any extra space.



// BruteForce Approach 2 (USING XOR)

int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.
    int ans = 0;
    // XOR all the elements:
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

// Time Complexity:- O(N), N = size of the given array. Reason: We are traversing the entire array.
// Space Complexity: O(1) as we are not using any extra space.






// Optimal Approach (Binary Search)

//INTUITION:-  We need to consider 2 different cases while using Binary Search in this problem. Binary Search works by reducing the search space by half. So, at first, we need to identify the halves and then eliminate them accordingly. In addition to that, we need to check if the current element i.e. arr[mid] is the ‘single element’.
/* If we can resolve these two cases, we can easily apply Binary Search in this algorithm.
How to check if arr[mid] i.e. the current element is the single element:
A crucial observation to note is that if an element appears twice in a sequence, either the preceding or the subsequent element will also be the same. But only for the single element, this condition will not be satisfied. So, to check this, the condition will be the following:
If arr[mid] != arr[mid-1] and arr[mid] != arr[mid+1]: If this condition is true for arr[mid], we can conclude arr[mid] is the single element.
The above condition will throw errors in the following 3 cases:
If the array size is 1.
If ‘mid’ points to 0 i.e. the first index.
If ‘mid’ points to n-1 i.e. the last index.
Note: At the start of the algorithm, we address the above edge cases without requiring separate conditions during the check for arr[mid] inside the loop. And the search space will be from index 1 to n-2 as indices 0 and n-1 have already been checked.
Resolving edge cases:
If n == 1: This means the array size is 1. If the array contains only one element, we will return that element only.
If arr[0] != arr[1]: This means the very first element of the array is the single element. So, we will return arr[0].
If arr[n-1] != arr[n-2]: This means the last element of the array is the single element. So, we will return arr[n-1]. */


int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size(); //size of the array.

    //Edge cases:
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if arr[mid] is the single element:
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        //we are in the left:
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
                || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            //eliminate the left half:
            low = mid + 1;
        }
        //we are in the right:
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }

    // dummy return statement:
    return -1;
}


// Time Complexity:- O(logN), N = size of the given array. Reason: We are basically using the Binary Search algorithm.
// Space Complexity: O(1) as we are not using any extra space. 

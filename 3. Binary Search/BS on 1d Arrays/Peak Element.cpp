// Bruteforce Approach

//INTUITION: A simple approach involves iterating through the array and checking specific conditions for each element to determine the peak. By considering all the necessary conditions, including edge cases, our final condition can be summarized as follows: If ((i == 0 or arr[i-1] < arr[i]) and (i == n-1 or arr[i] > arr[i+1])), we have found a peak. In such cases, we can return the index of the element satisfying this condition.

int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array.

    for (int i = 0; i < n; i++) {
        //Checking for the peak:
        if ((i == 0 || arr[i - 1] < arr[i])
                && (i == n - 1 || arr[i] > arr[i + 1])) {
            return i;
        }
    }
    // Dummy return statement
    return -1;
}

// Time Complexity:- O(N), N = size of the given array. Reason: We are traversing the entire array.
// Space Complexity: O(1) as we are not using any extra space.



// Optimal Approach

int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array.

    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else high = mid - 1;
    }
    // Dummy return statement
    return -1;
}


// Time Complexity:- O(logN), N = size of the given array. Reason: We are basically using binary search to find the minimum.
// Space Complexity: O(1) Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).

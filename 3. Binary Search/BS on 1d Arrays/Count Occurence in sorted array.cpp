// Bruteforce Approach

// INTUITION:- The approach is simple. We will linearly search the entire array, and try to increase the counter whenever we get the target value in the array. Using a for loop that runs from 0 to n – 1, containing an if the condition that checks whether the value at that index equals target. If true then increase the counter, at last return the counter.

int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // counting the occurrences:
        if (arr[i] == x) cnt++;
    }
    return cnt;
}

// Time Complexity:-  O(N), N = size of the given array Reason: We are traversing the whole array.
// Space Complexity: O(1) as we are not using any extra space. 


// OPTIMAL APPROACH (Binary Search)

// INTUITION:- Total number of occurrences = last occurrence – first occurrence + 1

int firstOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            first = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return first;
}

int lastOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            last = mid;
            //look for larger index on the right
            low = mid + 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = firstOccurrence(arr, n, k);
    if (first == -1) return { -1, -1};
    int last = lastOccurrence(arr, n, k);
    return {first, last};
}

int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
    pair<int, int> ans = firstAndLastPosition(arr, n, x);
    if (ans.first == -1) return 0;
    return (ans.second - ans.first + 1);
}


// Time Complexity:-  O(2*logN), where N = size of the given array. Reason: We are basically using the binary search algorithm twice.
// Space Complexity: O(1) as we are using no extra space.

// Naive Approach (Linear Search)

    int ans = 0;
    //linear search on the answer space:
    for (long long i = 1; i <= n; i++) {
        long long val = i * i;
        if (val <= n * 1ll) {
            ans = i;
        } else {
            break;
        }
    }
    return ans;

// Time Complexity: O(N), N = the given number. Reason: Since we are using linear search, we traverse the entire answer space.
// Space Complexity: O(1) as we are not using any extra space.


// Optimal Approach I (In-built sqrt() function)

int floorSqrt(int n) {
    int ans = sqrt(n);
    return ans;
}

// Time Complexity: O(logN), N = size of the given array. Reason: We are basically using the Binary Search algorithm.
// Space Complexity: O(1) as we are not using any extra space.



// Optimal Approach II (Binary Search)

int floorSqrt(int n) {
    int low = 1, high = n;
    //Binary search on the answers:
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n)) {
            //eliminate the left half:
            low = mid + 1;
        }
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }
    return high;
}

// Time Complexity: O(logN), N = size of the given array. Reason: We are basically using the Binary Search algorithm
// Space Complexity: O(1) as we are not using any extra space. 

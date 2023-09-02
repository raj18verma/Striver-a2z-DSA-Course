// BruteForce Approach

/* INTUITION: 
We will use a loop to traverse the array.
1. Inside the loop,
2. If vec[i] <= k: we will simply increase the value of k by 1.
3. Otherwise, we will break out of the loop.
4. Finally, we will return the value of k. */

int missingK(vector < int > vec, int n, int k) {
    // Write your code here.
        for (int i = 0; i < n; i++) {
        if (vec[i] <= k) k++; //shifting k
        else break;
    }
    return k;
}

// Time Complexity: O(N)
// Space Complexity: O(1)



// Optimal Approach

int missingK(vector < int > vec, int n, int k) {
    // Write your code here.
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return k + high + 1;
}


// Time Complexity: O(logN)
// Space Complexity: O(1)

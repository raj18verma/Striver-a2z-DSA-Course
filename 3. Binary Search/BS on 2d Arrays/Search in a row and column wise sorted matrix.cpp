// BruteForce Approach

/* INTUTION: One key point to notice here is that the first element of a row is not necessarily greater than the last element of the previous row (if it exists). This means the matrix is not necessarily entirely sorted although each row and column is sorted in non-decreasing order.
The extremely naive approach is to get the answer by checking all the elements of the given matrix. So, we will traverse the matrix and check every element if it is equal to the given ‘target’.  */

bool searchElement(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();

    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}

// Time Complexity: O(N*M)
// Space Complexity: O(1)


// Better Approach

/* INTUITION: The question specifies that each row in the given matrix is sorted. Therefore, to determine if the target is present in a specific row, we don’t need to search column by column. Instead, we can efficiently use the binary search algorithm. */

bool binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return true;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

bool searchElement(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        bool flag =  binarySearch(matrix[i], target);
        if (flag) return true;
    }
    return false;
}

// Time Complexity: O(N * log M)
// Space Complexity: O(1)



// Optimal Approach

/* INTUITION: We can enhance this method by adjusting how we move through the matrix */

bool searchElement(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m - 1;

    //traverse the matrix from (0, m-1):
    while (row < n && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) row++;
        else col--;
    }
    return false;
}

// Time Complexity: O(N+M)
// Space Complexity: O(1)

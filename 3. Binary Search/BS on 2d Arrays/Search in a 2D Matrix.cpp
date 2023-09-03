// BruteForce Approach 

/* INTUITION: The extremely naive approach is to get the answer by checking all the elements of the given matrix. So, we will traverse the matrix and check every element if it is equal to the given ‘target’. */


bool searchMatrix(vector<vector<int>>& matrix, int target) {
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

/* INTUION: The question specifies that each row in the given matrix is sorted. Therefore, to determine if the target is present in a specific row, we don’t need to search column by column. Instead, we can efficiently use the binary search algorithm.
To make the time complexity even better, we won’t use binary search on every row. We’ll focus only on the particular row where the target might be located. */

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


bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
            return binarySearch(matrix[i], target);
        }
    }
    return false;
}

// Time Complexity: O(N+logM)
// Space Complexity: O(1)



// Optimal Approach

/* INTUITION: If we flatten the given 2D matrix to a 1D array, the 1D array will also be sorted. By utilizing binary search on this sorted 1D array to locate the ‘target’ element, we can further decrease the time complexity.  */

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    //apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

// Time Complexity: O(log(N*M))
// Space Complexity: O(1)

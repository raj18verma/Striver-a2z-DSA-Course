// BruteForce Approach

/* INTUITION: In the question, it is clearly stated that we should return -1 if the matrix does not contain any 1.

The extremely naive approach is to traverse the matrix as usual using nested loops and for every single row count the number of 1’s. Finally, we will return the row with the maximum no. of 1’s. If multiple rows contain the maximum no. of 1’s we will return the row with the minimum index. */

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        int cnt_ones = 0;
        for (int j = 0; j < m; j++) {
            cnt_ones += matrix[i][j];
        }
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}


// Time Complexity: O(n X m)
// Space Complexity: O(1)



// Optimal Approach

/* Intuition: We cannot optimize the row traversal but we can optimize the counting of 1’s for each row. Instead of counting the number of 1’s, we can use the following formula to calculate the number of 1’s:
Number_of_ones = m(number of columns) – first occurrence of 1(0-based index). As, each row is sorted, we can find the first occurrence of 1 in each row using any of the following approaches:
lowerBound(1) upperBound(0)  firstOccurrence(1) */


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
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the rows:
    for (int i = 0; i < n; i++) {
        // get the number of 1's:
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}


// Time Complexity: O(n X logm)
// Space Complexity: O(1)

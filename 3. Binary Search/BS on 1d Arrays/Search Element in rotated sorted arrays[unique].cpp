// BruteForce Approach

// INTUITION:- One straightforward approach we can consider is using the linear search algorithm. Using this method, we will traverse the array to find the location of the target value. If it is found we will simply return the index and otherwise, we will return -1.

int search(vector<int>& arr, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == k)
            return i;
    }
    return -1;
}

// Time Complexity: O(N), N = size of the given array. Reason: We have to iterate through the entire array to check if the target is present in the array.
// Space Complexity: O(1) Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).



// Optimal Approach (Binary Search)

// INTUITION:- Key Observation: Though the array is rotated, we can clearly notice that for every index, one of the 2 halves will always be sorted. So, to efficiently search for a target value using this observation, we will follow a simple two-step process. 
/*
1. First, we identify the sorted half of the array. 
2. Once found, we determine if the target is located within this sorted half. 
      (i) If not, we eliminate that half from further consideration. 
      (ii) Conversely, if the target does exist in the sorted half, we eliminate the other half.       */


int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.

    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return mid;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}


// Time Complexity:- O(logN), N = size of the given array. Reason: We are using binary search to search the target.
// Space Complexity: O(1) Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).


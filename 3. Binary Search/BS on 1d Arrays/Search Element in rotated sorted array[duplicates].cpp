// BruteForce Approach (Linear Search)

bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    int n = arr.size(); // size of the array.
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) return true;
    }
    return false;
}


// Time Complexity:- O(N), N = size of the given array. Reason: We have to iterate through the entire array to check if the target is present in the array.
// Space Complexity: O(1) Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).



// Optimal Approach (Binary Search)

/* Everything is same, just check the edge case. */

bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    int n = arr.size(); // size of the array.
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return true;

        //Edge case:
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

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
    return false;
}


// Time Complexity:- O(logN) for the best and average case. O(N/2) for the worst case. Here, N = size of the given array.Reason: In the best and average scenarios, the binary search algorithm is primarily utilized and hence the time complexity is O(logN). However, in the worst-case scenario, where all array elements are the same but not the target (e.g., given array = {3, 3, 3, 3, 3, 3, 3}), we continue to reduce the search space by adjusting the low and high pointers until they intersect. This worst-case situation incurs a time complexity of O(N/2). 
// Space Complexity: O(1) Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).

/* Intuition :- We will solve this problem using the lower-bound algorithm which is basically a modified version of the classic Binary Search algorithm. 
The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.
On deep introspection of the given problem, we can easily understand that we have to find the correct position or the existing position of the target number in the given array.
Now, if the element is not present, we have to find the nearest greater number of the target number. So, basically, we are trying to find an element arr[ind] >= x and hence the lower bound of the target number i.e. x.
The lower bound algorithm returns the first occurrence of the target number if the number is present and otherwise, it returns the nearest greater element of the target number. */

int searchInsert(vector<int>& arr, int x) {
    int n = arr.size(); // size of the array
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


// Time Complexity:- O(logN), where N = size of the given array. Reason: We are basically using the Binary Search algorithm.
// Space Complexity: O(1) as we are using no extra space.

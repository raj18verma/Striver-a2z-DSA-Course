// Bruteforce Approach (LINEAR SEARCH)

// INTUITION: Find minimum in the entire array.

int findMin(vector<int>& arr) {
    int n = arr.size(); // size of the array.
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        // Always keep the minimum.
        mini = min(mini, arr[i]);
    }
    return mini;
}

// Time Complexity: O(N), N = size of the given array. Reason: We have to iterate through the entire array to check if the target is present in the array.
// Space Complexity: O(1) Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).



// Optimal Approach (BINARY SEARCH)

// Intuition: Same as Searching element in sorted array.
/* Example:{4,5,1,2,3}
low=0,high=4,mid=2
Check if arr[low] <= arr[mid], its not, 
So right part is sorted. 
We take ans=min(ans,arr[2]) => ans=1, and high = mid-1.

low=0,high=1,mid=0;
arr[low]<=arr[mid] = true. 
So we update ans as min(ans,arr[0]) => ans=1; 
Since the left part was sorted low=mid+1. Which makes low = high = 1.

low=1,high=1,mid=1
arr[low] <= arr[mid] = true. 
So we update ans as min(ans,arr[1]) => ans=1;  
Since the left part was sorted low=mid+1. Which makes low = 2. Loop Stops. */


int findMin(vector<int>& arr)
{
	// Write your code here.
	int n=arr.size();
	int low=0, high=n-1, ans=INT_MAX;

	while(low<=high){
		int mid=(low+high)/2;
		if(arr[low]<=arr[mid]){
			ans=min(ans,arr[low]);
			low=mid+1;
		}else{
			ans=min(ans,arr[mid]);
			high=mid-1;
		}
	}
	return ans;
}

// Time Complexity:-  O(logN), N = size of the given array. Reason: We are basically using binary search to find the minimum.
//Space Complexity: O(1) Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).

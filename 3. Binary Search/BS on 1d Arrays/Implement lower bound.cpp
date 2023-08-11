// BRUTEFORCE APPRAOCH  (Linear Search)

//Let’s understand how we can find the answer using the linear search algorithm. With the knowledge that the array is sorted, our approach involves traversing the array starting from the beginning. During this traversal, each element will be compared with the target value, x. The index, i, where the condition arr[i] >= x is first satisfied, will be the answer.

int lowerBound(vector<int> arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] >= x) {
            // lower bound found:
            return i;
        }
    }
    return n;
}

// Time Complexity:- O(N)
// Space Complexity:- O(1) as we are using no extra space.


// Optimal Approach (Binary Search)

/*As the array is sorted, we will apply the Binary Search algorithm to find the index. The steps are as follows: We will declare the 2 pointers and an ‘ans’ variable initialized to n i.e. the size of the array(as If we don’t find any index, we will return n).

1. Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index, and high will point to the last index.
2. Calculate the ‘mid’: Now, we will calculate the value of mid using the following formula: mid = (low+high) // 2 ( ‘//’ refers to integer division)
3. Compare arr[mid] with x: With comparing arr[mid] to x, we can observe 2 different cases:
               (i) Case 1 – If arr[mid] >= x: This condition means that the index mid may be an answer. So, we will update the ‘ans’ variable with mid and search in the left half if there is any smaller index that satisfies the same condition. Here, we are eliminating the right half.
              (ii) Case 2 – If arr[mid] < x: In this case, mid cannot be our answer and we need to find some bigger element. So, we will eliminate the left half and search in the right half for the answer.
                   The above process will continue until the pointer low crosses high. */



int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int low=0;
	int high=n-1;
	int ans=n;

	while(low<=high){
		int mid=(low+high)/2;

		//maybe an answer
		if(arr[mid]>=x){
			ans=mid;
			
		//look for more smaller index on left	
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	return ans;
}

// Time Complexity:- O(logN), where N = size of the given array. Reason: We are basically using the Binary Search algorithm
// Space Complexity:- O(1) as we are using no extra space.

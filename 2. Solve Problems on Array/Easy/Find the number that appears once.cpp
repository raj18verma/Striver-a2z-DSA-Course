// BruteForce 

int getSingleElement(vector<int> &arr) {
    // Size of the array:
    int n = arr.size();

    //Run a loop for selecting elements:
    for (int i = 0; i < n; i++) {
        int num = arr[i]; // selected element
        int cnt = 0;

        //find the occurrence using linear search:
        for (int j = 0; j < n; j++) {
            if (arr[j] == num)
                cnt++;
        }

        // if the occurrence is 1 return ans:
        if (cnt == 1) return num;
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
}


// T.C --> O(N2), where N = size of the given array. Reason: For every element, we are performing a linear search to count its occurrence. The linear search takes O(N) time complexity. And there are N elements in the array. So, the total time complexity will be O(N2).
// S.C --> O(1) as we are not using any extra space.




// Optimal Approach (Using XOR)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;

        for(int i=0; i<nums.size(); i++){
            ans=ans^nums[i];
        }
        return ans;
    }
};


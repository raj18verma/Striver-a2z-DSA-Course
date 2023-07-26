// Coding Ninjas --> https://www.codingninjas.com/studio/problems/ninja-and-the-sorted-check_6581957?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

int isSorted(int n, vector<int> a) {
    // Write your code here.
    for(int i=0; i<n-1; i++){
        if(a[i]>a[i+1])
        return 0;
    }
    return 1;
}


// Leetcode --> https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size();

        for(int i=1; i<n; i++){
            if(nums[i-1]>nums[i]){
                count++;
            }
        }
        if(nums[n-1]>nums[0]){
            count++;
        }

        return count<=1;
    }
};

// Better Approach

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sumArray=0;
        for(int i=0; i<nums.size(); i++){
            sumArray=sumArray+nums[i];
        }

        int expectedSum=(n*(n+1)/2);
        int requiredNum= expectedSum-sumArray;
        return requiredNum;
    }
};


// Optimal Approach (XOR Approach)
int missingNumber(int A[], int N)
{
    int ans = 0 ; 
    for(int i=0 ; i<N-1 ; i++){
        ans = ans^A[i];
    }
    for(int i=1 ; i<=N ; i++){
        ans = ans^i;
    }
    
    return ans ;
    
}

// BruteForce Approach

//INTUITION: A straightforward but basic solution is to examine consecutive sequences for each element in the given array. For every element x, we will try to find the consecutive elements, x+1, x+2, x+3, and so on using the linear search algorithm. Thus, we will check the length of the longest consecutive subsequence we can build for every element x. Among all the lengths we will consider the maximum one.

#include <bits/stdc++.h>
bool linear_search(vector<int>&arr, int target){
    int n=arr.size();
    for(int i=0; i<n; i++){
        if(arr[i]==target){
            return true;
        }
    }
    return false;
}

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    int longest=1;

    for(int i=0; i<n; i++){
        int x=arr[i];
        int count=1;

        while(linear_search(arr,x+1)==true){
            x=x+1;
            count=count+1;
        }
        longest=max(longest,count);
    }
    return longest;
}

// T.C :- O(N2), N = size of the given array. Reason: We are using nested loops each running for approximately N times.
// S.C :- O(1), as we are not using any extra space to solve this problem.


// Better Solution (Sorting)

#include <bits/stdc++.h>
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    if (n == 0) return 0;

    //sort the array:
    sort(arr.begin(), arr.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    //find longest sequence:
    for (int i = 0; i < n; i++) {
        if (arr[i] - 1 == lastSmaller) {
            //a[i] is the next element of the
            //current sequence.
            cnt += 1;
            lastSmaller = arr[i];
        }
        else if (arr[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest, cnt);
    }
    return longest;

}

// T.C:- O(NlogN) + O(N), N = size of the given array. Reason: O(NlogN) for sorting the array. To find the longest sequence, we are using a loop that results in O(N).
// S.C:- O(1), as we are not using any extra space to solve this problem. 




//Optimal Approach (Using Set Data Structure)

//INTUITION:- We will adopt a similar approach to the brute-force method but with optimizations in the search process. Instead of searching sequences for every array element as in the brute-force approach, we will focus solely on finding sequences only for those numbers that can be the starting numbers of the sequences. This targeted approach narrows down our search and improves efficiency.

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(arr[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}


// T.C:- O(N) + O(2*N) ~ O(3*N), where N = size of the array. Reason: O(N) for putting all the elements into the set data structure. After that for every starting element, we are finding the consecutive elements. Though we are using nested loops, the set will be traversed at most twice in the worst case. So, the time complexity is O(2*N) instead of O(N2).
// S.C:- O(N), as we are using the set data structure to solve this problem.

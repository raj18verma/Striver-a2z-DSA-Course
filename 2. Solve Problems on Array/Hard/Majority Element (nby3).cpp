/*Observation: How many integers can occur more than floor(N/3) times in the given array:
If we closely observe, in the given array, there can be a maximum of two integers that can occur more than floor(N/3) times. Let’s understand it using the following scenario:
Assume there are 8 elements in the given array. Now, if there is any majority element, it should occur more than floor(8/3) = 2 times. So, the majority of elements should occur at least 3 times. Now, if we imagine there are 3 majority elements, then the total occurrence of them will be 3X3 = 9 i.e. greater than the size of the array. But this should not happen. That is why there can be a maximum of 2 majority elements.*/


// Bruteforce Approach

/* 1. We will run a loop that will select the elements of the array one by one.
   2. Now, for each unique element, we will run another loop and count its occurrence in the given array.
   3. If any element occurs more than the floor of (N/3), we will include it in our answer. 
   4. While traversing if we find any element that is already included in our answer, we will just skip it. */

vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array
    vector<int> ls; // list of answers

    for (int i = 0; i < n; i++) {
        //selected element is v[i]:
        // Checking if v[i] is not already
        // a part of the answer:
        if (ls.size() == 0 || ls[0] != v[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // counting the frequency of v[i]
                if (v[j] == v[i]) {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ls.push_back(v[i]);
        }

        if (ls.size() == 2) break;
    }

    return ls;
}

// T.C --> O(N2), where N = size of the given array. Reason: For every element of the array the inner loop runs for N times. And there are N elements in the array. So, the total time complexity is O(N2).
// S.C --> O(1) as we are using a list that stores a maximum of 2 elements. The space used is so small that it can be considered constant.



// Better Approach (HASHING)
/* 1. Use a hashmap and store the elements as <key, value> pairs. (Can also use frequency array based on the size of nums).
      Here the key will be the element of the array and the value will be the number of times it occurs. 
   2. Traverse the whole array and update the occurrence of each element. 
   3. After that, check the map if the value for any element is greater than the floor of N/3. 
         3.1 If yes, include it in the list. 
         3.2 Else iterate forward.
   4. Finally, return the list. */

vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array
    vector<int> ls; // list of answers

    //declaring a map:
    map<int, int> mpp;
    // least occurrence of the majority element:
    int mini = int(n / 3) + 1;
    //storing the elements with its occurnce:
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
        //checking if v[i] is
        // the majority element:
        if (mpp[v[i]] == mini) {
            ls.push_back(v[i]);
        }
        if (ls.size() == 2) break;
    }
    return ls;
}

// T.C --> O(N*logN), where N = size of the given array. Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN).
// If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).

// S.C --> O(N) as we are using a map data structure. We are also using a list that stores a maximum of 2 elements. That space used is so small that it can be considered constant.




//Optimised Approach (Boyer Moore's Voting Algorithm)

#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n=arr.size();
    int cnt1=0, cnt2=0;
    int ele1=INT_MIN;
    int ele2=INT_MIN;


// applying the Extended Boyer Moore's Voting Algorithm:
    for(int i=0; i<n; i++){
        if(cnt1==0 && ele2!=arr[i]){
            cnt1++;
            ele1=arr[i];
        }else if(cnt2==0 && ele1!=arr[i]){
            cnt2++;
            ele2=arr[i];
        }

        else if(arr[i]==ele1)cnt1++;
        else if(arr[i]==ele2)cnt2++;

        else{
            cnt1--, cnt2--;
        }
    }
    vector<int>temp; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1=0, cnt2=0;
    for(int i=0; i<n; i++){
        if(ele1==arr[i])cnt1++;
        if(ele2==arr[i])cnt2++;
    }
    int mini= (int)(n/3)+1;
    if(cnt1>=mini) temp.push_back(ele1);
    if(cnt2>=mini) temp.push_back(ele2);


    // if it is told to sort the answer array:
    sort(temp.begin(),temp.end());
    return temp;
}


// T.C --> O(N) + O(N), where N = size of the given array. Reason: The first O(N) is to calculate the counts and find the expected majority elements. The second one is to check if the calculated elements are the majority ones or not.
// S.C --> O(1) as we are only using a list that stores a maximum of 2 elements. The space used is so small that it can be considered constant.

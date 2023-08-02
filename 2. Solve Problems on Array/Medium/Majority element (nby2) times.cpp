// BruteForce Approach

// 1. We will run a loop that will select the elements of the array one by one.
// 2. Now, for each element, we will run another loop and count its occurrence in the given array.
// 3. If any element occurs more than the floor of (N/2), we will simply return it.

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();

    for (int i = 0; i < n; i++) {
        //selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            // counting the frequency of v[i]
            if (v[j] == v[i]) {
                cnt++;
            }
        }
        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }
    return -1;
}


// T.C :- O(N2), where N = size of the given array. Reason: For every element of the array the inner loop runs for N times. And there are N elements in the array. So, the total time complexity is O(N2). 
// S.C :- O(1) as we use no extra space.




// Better Approach (HASHMAP)

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    //declaring a map:
    map<int, int> mpp;
    //storing the elements with its occurnce:
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
    }
    //searching for the majority element:
    for (auto it : mpp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }
    return -1;
}

// T.C :- O(N*logN) + O(N), where N = size of the given array. Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times. If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).
// S.C :-  O(N) as we are using a map data structure.




// Optimal Approach (MOORE'S VOTING ALGORITHM)

// INTUITION:- If the array contains a majority element, its occurrence must be greater than the floor(N/2). Now, we can say that the count of minority elements and majority elements is equal up to a certain point in the array. So when we traverse through the array we try to keep track of the count of elements and the element itself for which we are tracking the count. 
// After traversing the whole array, we will check the element stored in the variable. If the question states that the array must contain a majority element, the stored element will be that one but if the question does not state so, then we need to check if the stored element is the majority element or not. If not, then the array does not contain any majority element.


int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element
    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }
    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }
    if (cnt1 > (n / 2)) return el;
    return -1;
}


// T.C :- O(N) + O(N), where N = size of the given array. Reason: The first O(N) is to calculate the count and find the expected majority element. The second one is to check if the expected element is the majority one or not.
// Note: If the question states that the array must contain a majority element, in that case, we do not need the second check. Then the time complexity will boil down to O(N).

// S.C :- O(1) as we are not using any extra space.

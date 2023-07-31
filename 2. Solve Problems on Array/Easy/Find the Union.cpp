//Bruteforce approach

#include <bits/stdc++.h>
vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    int n1=a.size();
    int n2=b.size();

    set<int>st;
    for(int i=0; i<n1; i++){  
        st.insert(a[i]);             // O(n1logn)    n is the size of the set
    }
    for(int i=0; i<n2; i++){
        st.insert(b[i]);            // O(n2logn)     n is the size of the set
    }
    vector<int>temp;
    for(auto it:st){                // o(n1+n2)      the size of arrays a and b
        temp.push_back(it);
    }
    return temp;
}

//T.C --> O(n1logn + n2logn) + O(n1+n2)
//S.C --> O(n1+n2) for taking external set  +   o(n1+n2) temp array is used to return the answer not to solve the problem





//Optimal approach (Two Pointer):-

#include <bits/stdc++.h>
vector < int > sortedArray(vector < int > a, vector < int > b) {
  int n=a.size();
  int m=b.size();
  int i = 0, j = 0; // pointers
  vector < int > Union; // Uninon vector
  while (i < n && j < m) {
    if (a[i] <= b[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != a[i])
        Union.push_back(a[i]);
      i++;
    } else // case 3
    {
      if (Union.size() == 0 || Union.back() != b[j])
        Union.push_back(b[j]);
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != a[i])
      Union.push_back(a[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != b[j])
      Union.push_back(b[j]);
    j++;
  }
  return Union;

}


//T.C -->  O(m+n), Because at max i runs for n times and j runs for m times. When there are no common elements in arr1 and arr2 and all elements in arr1, arr2 are distinct. 
//S.C -->  O(m+n) {If Space of Union ArrayList is considered} & O(1) {If Space of union ArrayList is not considered}

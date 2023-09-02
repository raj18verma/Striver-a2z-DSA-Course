// BruteForce Approach (Linear Search)

/* Intuition: We can guarantee that our answer will lie between the range from 1 to m i.e. the given number. So, we will perform a linear search on this range and we will find the number x, such that
func(x, n) = m. If no such number exists, we will return -1.
Note: func(x, n) returns the value of x raised to the power n i.e. x^n. */

long long func(int base, int exp) {
    long long result = 1;
    
    while (exp > 0) {
        if (exp % 2 == 1) {  // If exp is odd
            result *= base;
        }
        base *= base;  // Square the base
        exp /= 2;       // Divide exp by 2
    }
    
    return result;
}


int NthRoot(int n, int m) {
  // Write your code here.
  for (int i = 0; i < m; i++){
    long long val = func(i,n);
    if(val==m) return i;
    else if(val>m) break;
  }
  return -1;
}

// Time Complexity: O(M), M = the given number. Reason: Since we are using linear search, we traverse the entire answer space.
// Space Complexity: O(1) as we are not using any extra space.



// Optimal Approach (Binary Search)

/* Intuition:  The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.
Now, we are not given any sorted array on which we can apply binary search. But, if we observe closely, we can notice that our answer space i.e. [1, n] is sorted. So, we will apply binary search on the answer space. */

int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int n, int m) {
  // Write your code here.
  int low=1, high=m;

  while(low<=high){
  int mid=(low+high)/2;
  
        int midN = func(mid, n, m);
        if (midN == 1) {
            return mid;
        }
        else if (midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Time Complexity:- O(log2m)*(log2n)
// Space Complexity:- O(1)

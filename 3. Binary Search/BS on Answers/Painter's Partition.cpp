// BruteForce Approach

/* Intuition: Same as book allocation */

int countPainters(vector<int> &boards, int time) {
    int n = boards.size(); //size of array.
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++) {
        if (boardsPainter + boards[i] <= time) {
            //allocate board to current painter
            boardsPainter += boards[i];
        }
        else {
            //allocate board to next painter
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    for (int time = low; time <= high; time++) {
        if (countPainters(boards, time) <= k) {
            return time;
        }
    }
    return low;
}


// Optimal Approach

int countPainters(vector<int> &boards, int time) {
    int n = boards.size(); //size of array.
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++) {
        if (boardsPainter + boards[i] <= time) {
            //allocate board to current painter
            boardsPainter += boards[i];
        }
        else {
            //allocate board to next painter
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int painters = countPainters(boards, mid);
        if (painters > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;

}

// Time and Space Complexity:- Same as Book Allocation


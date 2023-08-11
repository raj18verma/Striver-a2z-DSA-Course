int findFloor(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] <= x) {
            ans = arr[mid];
            low = mid + 1; // look on the right
        } else {
            high = mid - 1; // look on the left
        }
    }

    return ans;
}

int findCeil(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= x) {
            ans = arr[mid];
            high = mid - 1; // look on the left
        } else {
            low = mid + 1; // look on the right
        }
    }

    return ans;
}

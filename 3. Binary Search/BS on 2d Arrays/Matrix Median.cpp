// BruteForce Approach

/* INTUITION: The approach is very simple, just fill all elements in a linear array sort the array using the sort function, and then find the middle value (Median).  */

int Findmedian(int arr[3][3], int row, int col)
{
  int median[row * col];
  int index = 0;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      median[index] = arr[i][j];
      index++;
    }
  }
 
  return median[(row * col) / 2];
}


// Optimal Approach

/* INTUITON: Find the minimum and maximum element in the given array. By just traversing the first column, we find the minimum element and by just traversing the last column, we find the maximum element.
 Now find the middle element of the array one by one and check in the matrix how many elements are present in the matrix. */

int countSmallerThanMid(vector<int> &row, int mid)
{
  int l = 0, h = row.size() - 1;
  while (l <= h)
  {
    int md = (l + h) >> 1;
    if (row[md] <= mid)
    {
      l = md + 1;
    }
    else
    {
      h = md - 1;
    }
  }
  return l;
}

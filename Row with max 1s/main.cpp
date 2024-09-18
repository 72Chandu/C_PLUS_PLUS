/*N = 4 , M = 4  Arr[][] = {{0, 1, 1, 1},{0, 0, 1, 1},{1, 1, 1, 1},{0, 0, 0, 0}}
Output: 2   Row 2 contains 4 1's (0-based indexing).

Example 2: N = 2, M = 2 Arr[][] = {{0, 0}, {1, 1}}
Output: 1  Row 1 contains 2 1's (0-based indexing).

int ans = 0; // Initialize with 0 since you're finding max
int maxcount = 0;
int index = -1; // Initialize with -1 to indicate no occurrence of 1s yet
for (int i = 0; i < n; i++) {
    int currentCount = 0; // Count of 1s in the current row
    for (int j = 0; j < m; j++) {
        if (a[i][j] == 1) {
            currentCount++; // Increment count of 1s
        }
    }
    if (currentCount > maxcount) {
        maxcount = currentCount; // Update maxcount
        ans = maxcount; // Update ans
        index = i; // Update index
    }
}//o(n*m)
*/
int rowWithMax1s(vector<vector<int> >a, int n, int m) {
	    int ans = 0; // Initialize with 0 since you're finding max
        int maxcount = 0;
        int index = -1; // Initialize with -1 to indicate no occurrence of 1s yet
        int row = 0, col = m - 1; // Start from the top-right corner
      while (row < n && col >= 0) {
         if (a[row][col] == 1) {
           maxcount++; // Increment count of 1s
           ans = max(ans, maxcount); // Update ans
           index = row; // Update index
           col--; // Move left in the same row
        } else {
        row++; // Move down to the next row
        maxcount = 0; // Reset count of 1s for the new row
    }
 }
return index;
	}// o(n+m)
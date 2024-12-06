//https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();   
        int m = grid[0].size(); 
        int count = 0;
        for (int i = 0; i < n; i++) {
            int lo = 0, hi = m - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (grid[i][mid] < 0) {
                    hi = mid - 1; // Move left to find the first negative
                } else {
                    lo = mid + 1; // Move right
                }
            }
            // `lo` now points to the first negative number in the row
            count += (m - lo); // Add all negative numbers in this row
        }
        return count;
    }
};
/*[[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Row 0:first negative at index 3.
Count = 4−3=1.
Row 1: first negative at index 3.
Count = 4−3=1.
Row 2:Binary search finds first negative at index 2.
Count = 4−2=2.
Row 3: Binary search finds first negative at index 0.
Count = 4−0=4.
1 + 1 + 2 + 4 = 8

(O(n * log(m))):
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();    // Number of rows
        int m = grid[0].size(); // Number of columns
        int count = 0;

        // Start from bottom-left corner
        int row = n - 1, col = 0;

        while (row >= 0 && col < m) {
            if (grid[row][col] < 0) {
                // All elements to the right of this cell are also negative
                count += (m - col);
                row--; // Move up to the previous row
            } else {
                col++; // Move right to the next column
            }
        }

        return count;
    }
};//(O(n + m)):

/*
Start at grid[3][0]=−1:
Add 4 (entire row is negative), move up to grid[2][0].

At grid[2][0]=1:
Move right to  grid[2][1]=1.

At grid[2][2]=−1:
Add 2 (remaining elements), move up to grid[1][2].

grid[1][3]=−1:
Add 1 (remaining element), move up.
*/

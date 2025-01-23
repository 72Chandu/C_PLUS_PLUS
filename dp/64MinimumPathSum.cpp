/*
https://leetcode.com/problems/minimum-path-sum/description/

2 opton either move right /down

col=n-1 we can move only in down
row=m-1 we can move only in right 
rest we have 2 option 

*/
//for recurrsion 2^nxm
//Approach-1 (Recur + Memoization) : O(m*n)
class Solution {
public:
    int MPS(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& dp) {
        
        if(i == m-1 && j == n-1) return dp[i][j] = grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        if(i == m-1) { //we can only go right
            return dp[i][j] = grid[i][j] + MPS(grid, i, j+1, m, n, dp);
        } else if(j == n-1) { //we can go only down
            return dp[i][j] = grid[i][j] + MPS(grid, i+1, j, m, n, dp);
        } else {
            return dp[i][j] = grid[i][j] + min(MPS(grid, i+1, j, m, n, dp), MPS(grid, i, j+1, m, n, dp));
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return MPS(grid, 0, 0, m, n, dp);
    }
};

//Approach-2 (Bottom Up DP) : O(m*n)
class Solution {
public:
    int DFS(vector<vector<int>>& grid, int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        //dp[i][j] -> min path sum to reach [i][j] from [0][0]
        for(int i = 1; i<m; i++) //fill 1st col 
            dp[i][0] = dp[i-1][0]+grid[i][0];
        
        for(int j = 1; j<n; j++)   //fill 1st row 
            dp[0][j] = dp[0][j-1]+grid[0][j];

        for(int i = 1; i<m; i++) { //filing remainig 
            for(int j = 1; j<n; j++) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return DFS(grid, m, n);
    }
};

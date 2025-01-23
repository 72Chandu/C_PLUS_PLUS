/*
https://leetcode.com/problems/minimum-falling-path-sum/description/
A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position 
(row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

matrix = [[2,1,3],
         [6,5,4],
         [7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
if we start with row=0, then col should (col=0;col<n;col++)

row=0, minsum=infinity
for(col=0;col<n;col++){
    minsum=min(minsum, solve(matrix,row,col)) the fn will travese all the path and give the suitabel answeer
}
return minsum;
the path wil be according to question
(row+1,col-1), 
(row +1,col),
(row+1,col+1).

int solve(matrix, row , col){
    if(row==n-1){ last row me pahuch gaya
        return matrix[row][col]; ye value ko uper wale ko bhej do o add kar lega 
    }
    
    minsum=infinity sum=matrix[row][col];
   3 posiblilty hai or tino se humko minimum sum nikalna hai
  if(row+1<n and col-1>=0) minsum=min(minsum,sum+solve(matrix,row+1,col-1))
   if(row+1<n) minsum=min(minsum,sum+solve(matrix,row+1,col))
    if(row+1<n and col+1<n)minsum=min(minsum,sum+solve(matrix,row+1,col+1))
    
}
*/
//Approach-1 (Recur + Memoization) : O(m*n) (New test Case has been added, this will give TLE in last Test Case) (49 / 50 testcases passed)
//T.C : O(m*n)
int n;
    int dp[101][101];

    int solve(vector<vector<int>>& matrix, int row, int col) {
        if (row == n - 1) {
            return matrix[row][col];
        }
        if (dp[row][col] != -1) return dp[row][col];

        int sum = matrix[row][col];
        int minsum = INT_MAX;

        if (row + 1 < n && col - 1 >= 0) 
            minsum = min(minsum, sum + solve(matrix, row + 1, col - 1));

        if (row + 1 < n) 
            minsum = min(minsum, sum + solve(matrix, row + 1, col));

        if (row + 1 < n && col + 1 < n) 
            minsum = min(minsum, sum + solve(matrix, row + 1, col + 1));

        return dp[row][col] = minsum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        memset(dp, -1, sizeof(dp));
        int result = INT_MAX;
        for (int col = 0; col < n; col++){
            result = min(result, solve(matrix, 0, col));
        }
        return result;
    }
//give tle 
//better way to write above code 
int n;
    int dp[101][101];

    int solve(vector<vector<int>>& matrix, int row, int col) {
        if (row == n - 1) {
            return matrix[row][col];
        }
        if (dp[row][col] != -1) return dp[row][col];

        int sum = matrix[row][col];
        int minsum = INT_MAX;
        
        
        for(int shift=-1;shift<=1;shift++){ //-1,0,1 
            if(row+1<n && col+shift<n && col+shift>=0){
                minsum = min(minsum, sum + solve(matrix, row + 1, col+shift));
            }
        }
        return dp[row][col] = minsum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        memset(dp, -1, sizeof(dp));
        int result = INT_MAX;
        for (int col = 0; col < n; col++) {
            result = min(result, solve(matrix, 0, col));
        }
        return result;
    }

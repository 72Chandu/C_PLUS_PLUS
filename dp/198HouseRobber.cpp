/*
https://leetcode.com/problems/house-robber/description/

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
it will automatically contact the police if two adjacent houses were broken into on the same night.
*/
int solveRec(vector<int>&v, int n){ // n-> represent the index of current house
        if(n<0) return 0;
        if(n==0) return v[0];

        int include=solveRec(v, n-2)+v[n];
        int exclude=solveRec(v,n-1)+0;
        return max(include, exclude);
    }
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        return solveRec(nums, n);
    }//tle
//-------------------------------------------------
int solveMem(vector<int>&v, int n , vector<int>&dp){ // n-> represent the index of current house
    if(n<0) return 0;
    if(n==0) return v[0];
    if(dp[n]!=-1) return dp[n];
    int include=solveMem(v, n-2 ,dp)+v[n];
    int exclude=solveMem(v,n-1,dp)+0;
    dp[n]= max(include, exclude);
    return dp[n];
}
int rob(vector<int>& nums) {
    int n=nums.size()-1;
    vector<int>dp(n+1,-1);
    return solveMem(nums, n , dp);
}
//-------------------------------------------------

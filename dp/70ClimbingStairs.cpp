/*
https://leetcode.com/problems/climbing-stairs/description/

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 
*/
int climbStairs(int n) {
    if(n==0) return 1;
    if(n==1) return 1;
    return climbStairs(n-2)+climbStairs(n-1);
}//tle
    
int climbStairs(int n) {
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-2]+dp[i-1];
    }
    return dp[n];
}
    

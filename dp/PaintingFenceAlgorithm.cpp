/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color. Since the answer can be large, return it modulo 10^9 + 7.

Examples:

Input : n = 2 k = 4
Output : 16
Explanation: We have 4 colors and 2 posts.
Ways when both posts have same color : 4 
Ways when both posts have diff color :4(choices for 1st post) * 3(choices for 2nd post) = 12

Input : n = 3 k = 2
Output : 6

Consider the following image, in which c, c’ and c” are the respective colors of posts i, i-1, and i -2.
c''  c' c      c''    c'      c          c''  c'   c 
                    green   green            red  green
                    SAME                       DIFF 
According to the constraint of the problem, c = c’ = c” is not possible simultaneously, so either c’ != c or c” != c or both. There are k – 1 possibility for c’ != c and k – 1 for c” != c.
diff = number of ways when color of last two posts is different
same = number of ways when color of last two posts is same
Total ways = diff + same

for n = 1
    diff = k, same = 0
    total = k

for n = 2
    diff = k * (k-1) //k choices for first post, k-1 for next
    same = k //k choices for common color of two posts
    total = k +  k * (k-1)

for n = 3
    diff = (previous total ways) * (k - 1)
          = (k + k * (k - 1) * (k - 1)
    same = previous diff ways
          = k * (k-1)


Hence, we deduce that,
total[i] = same[i] + diff[i]
same[i]  = diff[i-1]
diff[i]  = total[i-1] * (k-1)
*/
#include <bits/stdc++.h>
using namespace std;
long solveRec(int n, int k){
    if(n==1) return k;
    if(n==2) return (k+k*(k-1));
    int ans=(solveRec(n-2 ,k)+solveRec(n-1, k))*(k-1);
    return ans;
}
long countWays_dp(int n, int k, vector<int>&dp){
    if(n==1) return k;
    if(n==2) return (k+k*(k-1));
    if(dp[n]!=-1) return dp[n];
    dp[n]=(countWays_dp(n-2 ,k , dp)+countWays_dp(n-1, k , dp))*(k-1);
    return dp[n];
}//t=o(n)  s=o(n)
long countWays_TAB(int n, int k){
    vector<int>dp(n+1,0);
    dp[1]=k;
    dp[2]=(k+k*(k-1));
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-2]+dp[i-1])*(k-1);
    }
    return dp[n];
}
long countWays(int n, int k){// Returns count of ways to color k posts
    long total = k;  // There are k ways to color first post
    int mod = 1000000007;
    // There are 0 ways for single post to violate (same color) and k ways to not violate (different color)
    int same = 0, diff = k;
    for (int i = 2; i <= n; i++) { // Fill for 2 posts onwards
        same = diff;// Current same is same as previous diff
        diff = (total * (k - 1)) % 1000000007;// We always have k-1 choices for next pos
        total = (same + diff) % mod;// Total choices till i.
    }
    return total;
}//t=o(n)  s=o(1)

int main(){
    int n = 3, k = 2;
    cout << solveRec(n, k) << endl;
    vector<int>dp(n+1 , -1);
    cout << countWays_dp(n, k , dp) << endl;
    cout << countWays_TAB(n, k) << endl;
    cout << countWays(n, k) << endl;
    return 0;
}




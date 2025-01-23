/*
https://leetcode.com/problems/longest-common-subsequence/description/
                             (abcde , ace) +1 (a is comman)
                                       |
                                    ( bcde, ce)  return max(1,2)
                                   /         \
                            (bcde,e)         (cde,ce) +1(c is comman)
                            /   \                      |
return 0 no comman  (bcde, "")   (cde,e)              (de,e) ->max(1,0)
                                /     \                /    \
return 0                    (cde,"") (de,e)      1+ (e,e)  (de,"") return 0
                                      /  \
                return 0        (de,"") (e,e)+1
                              
repeting sub problem hai so we use dp
*/
int t[1001][1001];
    int solve(string& s1, string& s2, int m, int n) {
        if(m == 0 || n == 0) return t[m][n] = 0;
        if(t[m][n] != -1) return t[m][n];
        if(s1[m-1] == s2[n-1]) return t[m][n] = 1 + solve(s1, s2, m-1, n-1);
        int include_m=solve(s1, s2, m, n-1);
        int include_n=solve(s1, s2, m-1, n);
        return t[m][n] = max(include_m, include_n);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        memset(t, -1, sizeof(t));
        return solve(text1, text2, m, n);
}
// s1 ke each char ke 2 possib  then 2^m, similarly for s2  2^n  => 2^m*2^n =o(2^m+n)
//bottom up 
/*
dp[i][j]-> longest comman subsequence between text1 of length i and text2 of length j
t[m][n]  t[m+1][n+1]  s1="abcde" s2="ace"

      0   1   2   3  
          a   c   e  
0     0   0   0   0
1  a  0              t[1][1] s1 ka length=1, s2 ka length=1. s1[1-1], s2[1-1]
2  b  0
3  c  0
4  d  0
5  e  0
          
        
*/
int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector>>dp(2,vector<int>(n+1));  // dp[i][j]-> longest comman subsequence between text1 of length i and text2 of length j
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0||j==0) dp[i][j]=0;
                else if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[m][n];
}

//bottom up approcah  space optimization
int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector>>dp(2,vector<int>(n+1));
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0||j==0) dp[i%2][j]=0;
                else if(text1[i-1]==text2[j-1]) dp[i%2][j]=1+dp[(i+1)%2][j-1];
                else dp[i%2][j]=max(dp[i%2][j-1],dp[(i+1)%2][j])
            }
        }
        return dp[m%2][n];
}

/*
case 1:
x=abcdgh -> n length     y=abedfh  -> m length   -> h include in anwer
       i                        i
if(x[n-1]==y[m-1]) x->n-1 and y-> m-1

case 2:
 
 x=abcdgh    y=abedfhr
        i            i
if(x[n-1]!=y[m-1]) 2 condition aries either (n-1 length of x match with m lenth of y ) or (n length of x match with m-1 lenth of y ) 

 x=abcdgh    y=abedfhr  |  x=abcdgh    y=abedfhr
   -----       -------       ------      ------  

*/
//recursive
int lcs(int n, int m, string s1, string s2){
        if(n==0 || m==0) return 0;
        if(s1[n-1]==s2[m-1]) return 1+lcs(n-1,m-1,s1,s2);//each time the lenth will inc by 1 after hitting this condition
        else return max(lcs(n,m-1,s1,s2),lcs(n-1,m,s1,s2));
}

//dp
int dp[1001][1001];//dp[n+1][m+1]
memset(dp,-1,sizeof(dp));
int lcs(int n, int m, string s1, string s2) {
    // Base case
    if (n == 0 || m == 0) return 0;
    // Check if the value is already calculated
    if (dp[n][m] != -1) return dp[n][m];
    // If characters at current indices match, include them in LCS
    if (s1[n - 1] == s2[m - 1])  return dp[n][m] = 1 + lcs(n - 1, m - 1, s1, s2, dp);
    // Otherwise, take the maximum LCS by excluding one character from either string
    else return dp[n][m] = max(lcs(n - 1, m, s1, s2, dp), lcs(n, m - 1, s1, s2, dp));
}
int calllcs(int n,int)

-> top down
int lcs(int n, int m, string s1, string s2) {
    // Initialize a DP table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the DP table bottom-up
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1]; // If characters match, extend the LCS
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // If characters don't match, take the maximum LCS
        }
    }

    // The LCS length is stored at the bottom-right corner of the DP table
    return dp[n][m];
}

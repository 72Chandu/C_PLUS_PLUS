/*
https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
s=mbadm  o/p=2 
                         m b a d m 
                         i       j
                             | i+1, j-1
                    m b a d m 
                      i   j 
insert b 1+ (i+1,j)     /\ not matching   1+ (i,j-1)  d ko left side me insert kar diye (m db a d m)so, move j
            m b a d m        m b a d m 
                i j            i j
 (i+1,j) +1     /\(i,j-1)+1          /\
     m b a d m     m b a d m       m b a d m    m b a d m 
           ij          ij

jab match nahi kare tab 2 possiblity 1.left wala charcter ko right side dal ke match kara do -> 1 insertion hoga
                                     2.right  wala charcter ko left side dal ke match kara do -> 1 insertion hoga
return karege dono me minimum value 
*/
int dp[501][501];
int solve(string &s, int i, int j){
    if(i>=j) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    if(s[i]==s[j]) return dp[i][j]=solve(s,i+1,j-1);
    else return dp[i][j]=1+ min(solve(s,i,j-1),solve(s,i+1,j));
}
int minInsertions(string s) {
     int n=s.length();
     memset(dp,-1,sizeof(dp));
     return solve(s,0,n-1);
}

//https://leetcode.com/problems/restore-the-array/description/
class Solution {
public:
    const int MOD = 1e9 + 7;
    int n;
    int solve(int start, string &s, int &k,vector<int>&dp){
        if(start>=n) return 1;
        if(dp[start]!=-1) return dp[start];
        if(s[start]=='0') return dp[start]=0;//no leading 0
        long ans=0;
        long long num=0;
        for(int end=start;end<n;end++){
            num=num*10 +(s[end]-'0');
            if(num>k) break;
            ans=(ans%MOD + solve(end+1,s,k,dp)%MOD)%MOD;
        }
        return dp[start]=ans;
    }
    int numberOfArrays(string s, int k) {
        n=s.length();
        vector<int>dp(n,-1);
        return solve(0,s,k,dp);
    }
};
/* 
start=0  end= move to 0 to 3
start=1  end= move to 1 to 3
we take take the string from start to end and check that    string <k, if >k break
                         0123    k=2000, [1,2000]
                        "1317"
       start= 1 |      start=13 |    start=131 |     1317 |
           "317"            "17"             "7"      
  start= 3|
      "17"

"253" s=e=0, num=num*10 +2 =0+2=2
s=0,e=1 num=num*10+5=25, 
*/

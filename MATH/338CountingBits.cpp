//https://leetcode.com/problems/counting-bits/description/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=0;i<=n;i++){
            int count=0;
            int num=i;
            while(num>0){
                count+=num%2;//check last bit
                num/=2; //right shift
            }
            ans[i]=count;
        }
        return ans;
    }
};
/*************************************/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i]=dp[i>>1]+(i&1);//dp[i]=dp[i/2]+(imod2)
        }
        return dp;
    }
};
/*
i	Binary	dp[i]=dp[i>>1]+(i&1)  dp[i]
0	 000	  dp[0] = 0	           0
1	 001	  dp[0] + 1 = 1	       1
2	 010	  dp[1] + 0 = 1	       1
3	 011	  dp[1] + 1 = 2	       2
4	 100	  dp[2] + 0 = 1	       1
5	 101	  dp[2] + 1 = 2	       2
*/

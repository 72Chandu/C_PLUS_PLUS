//https://leetcode.com/problems/profitable-schemes/description/
class Solution {
public:
    int dp[101][101][101];
    int thresholdProfit;
    int N;
    const int MOD=1e9+7;
    int solve(int i, int p, int people,vector<int>&group,vector<int>&profit){
        if(people>N) return 0;
        if(i==group.size()){
            if(p>=thresholdProfit) return dp[i][p][people]=1;
            return dp[i][p][people]=0;
        }
        if(dp[i][p][people]!=-1) return dp[i][p][people];
        long long taken=solve(i+1,min(thresholdProfit, p+profit[i]),people+group[i],group,profit)%MOD;
        long long not_taken=solve(i+1,p,people,group,profit)%MOD;
        return dp[i][p][people]=(taken%MOD + not_taken%MOD)%MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        N=n;
        thresholdProfit=minProfit;
        return solve(0,0,0,group,profit);
    }
};

//https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int dp[10001];
    int solve(vector<int>& nums, int n, int idx){
        if(idx==n-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int minjump=INT_MAX;
        for(int i=1;i<=nums[idx];i++){
            if(idx+i<n){
                int jump= solve(nums,n,idx+i);
                if(jump!=INT_MAX){
                    minjump=min(minjump,1+jump);
                }
            }
        }
        return dp[idx]=minjump;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return  solve(nums,n,0);
    }
};

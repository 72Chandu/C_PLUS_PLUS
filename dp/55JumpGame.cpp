/*
https://leetcode.com/problems/jump-game/description/

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

                                       2,3,1,1,4
                                       i
                                       
                                     1/              \ 2
                            2,3,1,1,4                 2,3,1,1,4
                              i                           i
                                                          
                 1/          2|       3\                  |1
            2,3,1,1,4    2,3,1,1,4    2,3,1,1,4          2,3,1,1,4
                i              i              i                i 
                                      (return true)            
                                                               |1
                                                               2,3,1,1,4
                                                                       i 
                                                                (return true) 

by obserbation we see the overlaping                               
*/
bool solve(vector<int>& nums , int n, int idx){
    if(idx==n-1) return true;
    
    if(idx>=n) return true;
    
    for(int i=1;i<=nums[idx]; i++){
        if(solve(nums,n,idx+i)==true){ //kisi path se true milega we got answer
            return true;
        }
    }
    return false;
}
bool canJump(vector<int>& nums){
    int n=nums.size();
    return solve(nums,n,0);
        
}
//dp 
int dp[10001];
bool solve(vector<int>& nums , int n, int idx){
    if(idx==n-1) return true;
    
    if(dp[idx]!=-1) return dp[idx];
    
    if(idx>=n) return dp[idx]=true;
    
    for(int i=1;i<=nums[idx]; i++){
        if(solve(nums,n,idx+i)==true){ //kisi path se true milega we got answer
            return dp[idx]=true;
        }
    }
    return dp[idx]=false;
}
bool canJump(vector<int>& nums){
    int n=nums.size();
    memset(dp,-1, sizeof(dp));
    return solve(nums,n,0);
}//o(n^k)  k=max(nums)

//bootom up 
bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> t(n, false);
        //t[i] = True means, you can reach index i
        
        t[0] = true; //Already at starting index
        
        for(int i = 1; i<n; i++) {
            for(int j = i-1; j>=0; j--) {
                if(j + nums[j] >= i && t[j]) { //here t[j] == true means you should be able to reach j also, 
                                               //then only you can plan to jump(j+nums[i])  from this jth index
                    t[i] = true;
                    break;
                }
            }
        }
        
        
        return t[n-1];

    }
    
    //OPTIMAL Solution (ACCEPTED)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0;
        int n            = nums.size();
        
        for(int i = 0; i<n; i++) {
            if(i > maxReachable) {
                return false;
            }
            maxReachable = max(maxReachable, nums[i]+i);
        }
        
        return true;
    }
};

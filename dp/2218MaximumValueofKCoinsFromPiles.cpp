//https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/
class Solution {  //Time : O(k*n)
public:
    int n;
    int dp[1001][2001];
    int solve(int i,vector<vector<int>>& piles, int k ){ //i-> denoting piles 
        if(i>=n) return 0;

        if(dp[i][k]!=-1) return dp[i][k];
        int not_taken=solve(i+1, piles,k);

        int taken=0;
        int sum=0;
        for(int j=0;j<min((int)piles[i].size(),k);j++){ //j->coin
            sum+=piles[i][j];
            if(k-(j+1)>=0){//remaining coin
                taken=max(taken,sum+solve(i+1,piles,k-(j+1)));
            }
        }
        return dp[i][k]=max(taken,not_taken);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,piles,k);
    }
};
/*
piles =  [ [1,100,3],     [7,8,9]]
               0              1   -> i
              /\              /\
        taken  not taken  taken  not taken
         /
    [1,100,3]
     j->
*/

//Approach-2 (Using Bottomm Up) : Time : O(k*n), where s = total coins
class Solution {
public:
    //t[i][j]-> max value when you have i piles and you can take  max j coin
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> t(n + 1, vector<int>(k + 1));
        for(int i = 1; i<= n; i++) { // i-> piles you visit 
            for(int coins = 0; coins <= k; coins++) { 
                int sum = 0;
                for(int currCoins = 0; currCoins <= min((int)piles[i - 1].size(), coins); currCoins++) {
                    if(currCoins > 0)
                        sum += piles[i-1][currCoins-1];
                    t[i][coins] = max(t[i][coins], sum + t[i-1][coins - currCoins]);
                    
                }
                
            }
            
        }
        return t[n][k];
    }
};

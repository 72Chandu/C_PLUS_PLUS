class Solution {
public:
    int n;
    int solve(string &s, int curr_index, int prev_val, vector<vector<int>>& dp) {
        if(curr_index >= n)  return 0;
        
        if(dp[curr_index][prev_val] != -1)  return dp[curr_index][prev_val];

        int flip    = INT_MAX;
        int no_flip = INT_MAX;

        if(s[curr_index] == '0') {
            if(prev_val == 1) {
                flip = 1 + solve(s, curr_index+1, 1, dp);//10 -> 11i-> now prev=1, cae2->10 -> 10i-> now it is not increasing
            } else {
                flip = 1 + solve(s, curr_index+1, 1, dp);// 00 case1-> 01 -> 01i ->now prev=1
                no_flip = solve(s, curr_index+1, 0, dp);// 00 case2-> 00 -> 00i ->now prev=0
            }
        }
        else if(s[curr_index] == '1'){
            if(prev_val == 1) {
                no_flip = solve(s, curr_index+1, 1, dp);//11 -> 11i-> now prev=1, cae2->11 -> 10i-> now it is not increasing
            } else {
                flip    = 1 + solve(s, curr_index+1, 0, dp);//01 case1-> 00 -> 00i ->now prev=0
                no_flip = solve(s, curr_index+1, 1, dp);//01 case1-> 01 -> 01i ->now prev=1
            }
        }
        return dp[curr_index][prev_val] =  min(flip, no_flip);
    }
    int minFlipsMonoIncr(string s) {
        n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(s, 0, 0, dp);
    }
};

//Approach-2 (Better Optimal Solution)
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count_of_ones = 0;
        int flips = 0;
        
        for(char &ch : s) {
            if(ch == '1')
                count_of_ones++;
            else {
                flips = min(flips+1, count_of_ones);
            }
        }
        
        return flips;
    }
};

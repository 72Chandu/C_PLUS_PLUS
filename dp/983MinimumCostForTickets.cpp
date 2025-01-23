//https://leetcode.com/problems/minimum-cost-for-tickets/description/
class Solution {
public:
    int dp[366];
    int solve(vector<int>& days, vector<int>& costs, int n, int i){
        if(i>=n) return 0; //you cant travel
        if(dp[i]!=-1) return dp[i];
        //1 day pass
        int cost_1=costs[0]+solve(days,costs,n,i+1);
        
        //7 days pass
        int j=i;
        int max_day=days[i]+7;
        while(j<n && days[j]<max_day){
            j++;
        }
        int cost_7=costs[1]+solve(days,costs,n,j);

        //30 days pass
        j=i;
        max_day=days[i]+30;
        while(j<n && days[j]<max_day){
            j++;
        }
        int cost_30=costs[2]+solve(days,costs,n,j);

        return dp[i]=min({cost_1,cost_7,cost_30});
    } 
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        memset(dp,-1,sizeof(dp));
        return solve(days,costs,n, 0);
    }
};
/*
days=[1,4,6,7,8,20]  cost=[2,7,15]
      2 2 2 2 2 2 =12
      2 7        2 =11  7=(1,2-x,3-x,4,5-x,6,7)
      15           =15
              1  i=0
         2/   \7      \ 15
     i=1 4     8 i=4   return
      2 /  7\  15\
  i=2  6 i=5 20 
*/

//Approach-2 (Bottom Up DP) [Time : O(max_day)] [Space : O(n)] //n = size of days vector
class Solution {
public:    
    int bottomUp(vector<int>& days, vector<int>& costs) {
        unordered_set<int> st(begin(days), end(days));
        int last_day = days.back();
        vector<int> t(last_day+1, 0);
        //t[i] = min cost to reach till day i of your travel plan
        t[0] = 0; //since, on day 0, we spend cost = 0
        
        for(int i = 1; i<=last_day; i++) {
            if(st.find(i) == st.end()) {
                t[i] = t[i-1]; //skip
                continue;
            }
            t[i] = INT_MAX; //you need to filter those days from 1 to 30 which are not in days vector
            int day_1_pass = t[max(0, i-1)] + costs[0];  //I come to i either by taking a 1-day pass from jth day
            int day_7_pass = t[max(0,i-7)] + costs[1];   //I come to i either by taking a 7-day pass from jth day
            int day_30_pass = t[max(0, i-30)] + costs[2]; //I come to i either by taking a 30-day pass from jth day
            t[i] = min({day_1_pass, day_7_pass, day_30_pass});
        }
        return t[last_day]; //minimum cost to travel till my last planned day
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return bottomUp(days, costs);     
    }
};

//Approach-3 (Moving from i = n-1 to 0    Simply replacing recursive calls with t
    int solve_bottom_up(vector<int>& days, vector<int>& costs, int n ) {
        vector<int> t(n+1, INT_MAX);
        t[n] = 0;
        for(int i = n-1; i>=0; i--) {
            int cost_1 = costs[0] + t[i+1];//1 day pass
            //7 day pass
            int j = i;
            int max_day = days[i] + 7;
            while(j < n && days[j] < max_day) {
                j++;
            }
            int cost_7 = costs[1] + t[j];
            //30 day pass
            j = i;
            max_day = days[i] + 30;
            while(j < n && days[j] < max_day) {
                j++;
            }
            int cost_30 = costs[2] + solve(days, costs, n, j);
            t[i] = min({cost_1, cost_7, cost_30});
        }
        return t[0];
    }

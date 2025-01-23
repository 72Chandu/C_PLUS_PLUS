/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
                            [1,4,2]
                             i |  buy 
                              [4,2]
                               i
profit =4-1=3    sell          /  \  not sell profit=0+1
                            [2]      [2] 
                             i        i 
                cooldown     |  sell /\ not sell
                             []i   []i    []i


*/

//Approach-1 (Recursion+Memoization)
class Solution {
public:
    int dp[5001][2];
    int maxP(vector<int>& prices, int day, int n, int buy) {
        if(day >= n)
            return 0;
        
        int profit = 0;
        if(dp[day][buy] != -1) {
            return dp[day][buy];
        }
        //buy   
        if(buy) {   // false->not buy, true-> buy 
            int consider= maxP(prices, day+1, n, false) - prices[day];//shelling-buy
            int not_consider= maxP(prices, day+1, n, true);//buy 
            profit = max({profit, consider, not_consider});
        } else { //sell
            int consider=  prices[day] + maxP(prices, day+2, n, true);//shelling +buy (shell ke baad next day cooldown hai so day +2)
            int not_consider= maxP(prices, day+1, n, false);//shell
            profit = max({profit, consider, not_consider}); 
        }
        
        return dp[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return maxP(prices, 0, n, true);//first day we should buy so true
    }
};

//Approach-2 (DP : O(n^2))
class Solution {
public:
    int maxP(vector<int>& prices, int& n) {
        if(n == 0 || n == 1)
            return 0;
        vector<int> t(n, 0);
        
        //t[i] = max profit at the end of ith day
        t[0] = 0; //no profit on 0th day
        t[1] = max(prices[1] - prices[0], 0); // max(bought_day_0 and sell_day_1, 0);
        
        /*  
            Let's analyse ith day, i.e. t[i] :
            i-th day can be :
            - BUY DAY   -> NO, because why would someone buy on last day
            
            - COOL DOWN -> YES, in that case, max-profit will be previsou's day profit (t[i] = t[i-1])
            
            - SELL DAY  -> If we choose to sell today, We will have to select the best buy day from j = 0 to j = (i-1)
                          So, profit = prices[j] - prices[i]; //i.e. we bought on day-j and sell on day-i
                          But, what about previous-profit of j i.e. t[j]. We need to consider that as well to find whole
                          maximum profit.
                          So, for that let's look previously to j :
                          Look at (j-1) -> It can't be buy-day, becuse we are already buying on jth day
                                        -> It can't be sell-day because, after you sell your stock on (j-1)th day, you cannot buy stock on the next day i.e. (jth) day (i.e., cooldown one day).
                                        -> It can only be cool-down day. max profit till (j-1)th day will be
                                            equal to its privous profit i.e. t[j-2]
                                            
                        So, profit at day i = prices[j] - prices[i] + t[j-2];
                          
        */
        
        for(int i = 2; i<n; i++) {
            t[i] = t[i-1]; //cool down
            
            //find best buy day from j  = 0 to i-1
            for(int j = 0; j<=i-1; j++) {
                
                int prev_profit = j>=2 ? t[j-2] : 0;
                
                t[i] = max(t[i], prices[i] - prices[j] + prev_profit);
            }
        }
        
        return t[n-1];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return maxP(prices, n);
    }
};

//Approach-3 (Optimizing Approach-1 to O(n))
class Solution {
public:
    int maxP(vector<int>& prices, int& n) {
        if(n == 0 || n == 1)
            return 0;
        
        /*
            if you notice, while finding the best j from 0 to i-1 (i.e. best buy day)
            t[i] = max(t[i], prices[i] - prices[j] + prev_profit);
            Here, (prices[i] - prices[j] + prev_profit) in this, prices[i] is not changing
            So, it can be written as (prices[i] + (prev_profit - prices[j]))
            We need maximum (prev_profit - prices[j]) = maxDiff
            i.e. (prices[i] + maxDiff)
            SO, we maintain maxDiff through out.
            
            Notice, (when j < 2), prev_profit = 0;
            
            we get, (prices[i] - prices[j])
            So, when j < 2, maxDiff = -prices[j];
            
        */
        
        vector<int> t(n, 0);
        int maxDiff = INT_MIN;
        
        for(int i = 0; i<n; i++) {
            if(i < 2)
                maxDiff = max(maxDiff, -prices[i]);
            if(i == 0)
                t[i] = 0;
            else if(i == 1)
                t[i] = max(prices[1] - prices[0], 0);
            else {
                //t[i] = max(cooldown, best buy privously to gain max profit after selling now);
                t[i]    = max(t[i-1], prices[i] + maxDiff);
                maxDiff = max(maxDiff, t[i-2] - prices[i]);
            }
        }
        
        return t[n-1];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return maxP(prices, n);
    }
};


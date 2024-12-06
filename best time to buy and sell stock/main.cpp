/*
Example 1:      Input: prices = [7,1,5,3,6,4]          Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:     Input: prices = [7,6,4,3,1]    Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
  
 -> if array are in dec order then profit is 0
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=prices[0];
        int maxprof=0;
        for(int i=1;i<prices.size();i++){
            maxprof=max(maxprof, prices[i]-minprice);
            minprice=min(prices[i],minprice);
        }
        return maxprof;
    }
};
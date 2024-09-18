/*Input:   price[] = {10, 22, 5, 75, 65, 80} Output:  87
Trader earns 87 as sum of 12, 75 
Buy at 10, sell at 22, 
Buy at 5 and sell at 80

Input:   price[] = {2, 30, 15, 10, 8, 25, 80}   Output:  100
Trader earns 100 as sum of 28 and 72
Buy at price 2, sell at 30
buy at 8 and sell at 80

Input:   price[] = {100, 30, 15, 10, 8, 25, 80}; Output:  72
Buy at price 8 and sell at 80.

Input:   price[] = {90, 80, 70, 60, 50}   Output:  0
Not possible to earn.

*/
1) Create a table profit[0..n-1] and initialize all values in it 0.
2) Traverse price[] from right to left and update profit[i] such that profit[i] stores maximum profit achievable from one transaction in subarray price[i..n-1]
3) Traverse price[] from left to right and update profit[i] such that profit[i] stores maximum profit such that profit[i] contains maximum achievable profit from two transactions in subarray price[0..i].
4) Return profit[n-1]
and profit[i+1..n-1] contains profit with two transactions.

int maxProfit(int price[], int n){
    int* profit = new int[n];//1
    for (int i = 0; i < n; i++)
        profit[i] = 0;
    int max_price = price[n - 1];//2
    for (int i = n - 2; i >= 0; i--) {
        if (price[i] > max_price)
            max_price = price[i];
            profit[i]= max(profit[i + 1], max_price - price[i]);
    }
    int min_price = price[0];//3
    for (int i = 1; i < n; i++) {
        // min_price is minimum price in price[0..i]
        if (price[i] < min_price)
            min_price = price[i];
            profit[i] = max(profit[i - 1],profit[i] + (price[i] - min_price));// b) (Buy, Sell) at (min_price, price[i]) and add profit of other trans. stored in profit[i]
    }
    int result = profit[n - 1];
    delete[] profit; // To avoid memory leak
    return result;
}
Time complexity: O(n)
Auxiliary space: O(n) 

Another approach:
---------------------------------------------------------------------------------------------
int maxtwobuysell(int arr[],int size) {
    int first_buy = INT_MIN;
      int first_sell = 0;
      int second_buy = INT_MIN;
      int second_sell = 0;
      for(int i=0;i<size;i++) {
          first_buy = max(first_buy,-arr[i]);//we set prices to negative, so the calculation of profit will be convenient
          first_sell = max(first_sell,first_buy+arr[i]); 
          second_buy = max(second_buy,first_sell-arr[i]);//we can buy the second only after first is sold
          second_sell = max(second_sell,second_buy+arr[i]);
       
    }
     return second_sell;
}
Time Complexity: O(N)
Auxiliary Space: O(1)
---------------------------------------------------------------------------------------------
Recursive Approach :
Every day, We have two choices: Buy/Sell this stock OR ignore it and move to the next one.
Along with day, we also need to maintain a capacity variable which will tell us how many transactions
are remaining and it will be of which type (Buy or Sell) .According to that we will make
recursive calls and calculate the answer We can do at most 4 transactions (Buy, Sell, Buy, Sell) in this order.
---------------------------------------------------------------------------------------------
int f(int idx, int buy, int prices[],int cap, int n){
    if (cap == 0)  return 0;
    if (idx == n)  return 0;
    int profit = 0;
    if (buy == 0) {// you can either buy or not buy(f(idx + 1, 0, prices,  cap, n))
      profit= max(-prices[idx]+ f(idx + 1, 1, prices,  cap, n), f(idx + 1, 0, prices,  cap, n));
    }
    else {// you can either sell or not sell
         profit = max( prices[idx]+ f(idx + 1, 0, prices, cap - 1, n),f(idx + 1, 1, prices,  cap, n));
    }
    return profit;
}
int maxtwobuysell(int prices[], int n){
    return f(0, 0, prices, 2, n);
}
 
Time Complexity : O(2^N)
Auxiliary Space : O(N)

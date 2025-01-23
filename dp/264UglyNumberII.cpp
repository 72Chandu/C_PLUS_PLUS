//https://leetcode.com/problems/ugly-number-ii/description/
#include <vector>
#include <algorithm>

class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> dp(n);
        dp[0] = 1; // The first ugly number is 1
        int p2 = 0, p3 = 0, p5 = 0;// Pointers for multiples of 2, 3, and 5
        for (int i = 1; i < n; ++i) {
            // Compute the next ugly number
            int nextUgly = std::min({dp[p2] * 2, dp[p3] * 3, dp[p5] * 5});
            dp[i] = nextUgly;

            // Increment the pointer(s) whose value matches the chosen minimum
            if (nextUgly == dp[p2] * 2) p2++;
            if (nextUgly == dp[p3] * 3) p3++;
            if (nextUgly == dp[p5] * 5) p5++;
        }
        return dp[n - 1];
    }
};

// m-2 using heap

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1; // Base case
        vector<int> primes = {2, 3, 5};
        priority_queue<long,vector<long>, greater<long>> minHeap; // Min-heap for generating numbers
        unordered_set<long> seen; // To avoid duplicates
        minHeap.push(1);
        seen.insert(1);
        long currentUgly = 1;
        for (int i = 0; i < n; ++i) {
            currentUgly = minHeap.top();
            minHeap.pop();
            // Generate next ugly numbers by multiplying with 2, 3, and 5
            for (int prime : primes) {
                long nextUgly = currentUgly * prime;
                if (!seen.count(nextUgly)) {
                    seen.insert(nextUgly);
                    minHeap.push(nextUgly);
                }
            }
        }
        return currentUgly;
    }
};


/*
https://leetcode.com/problems/ugly-number-ii/description/

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

8->2*2*2*2
6->2*3
14->2*7 -> not a ugly no because of 7
Given an integer n, return the nth ugly number.
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
1->2^0 * 3^0 *5^0
2->2^1 * 3^0 *5^0
3->2^0 * 3^1 *5^0

brute force
n=34 -> 2*17 ,  34/2=17 
n=12
   2->  12/2=6 , 6/2=3
   3-> 3/3=1 
   5->1/5 x
   2*2*3
check each no is ungley or not . if ungley the inc the count=tc=n*log(n)
optimal approch -> o(n)

any ungley no can be repesented by only =2^a * 3^b * 5^c
  if you multiply a ugley no either by 2,3,5 it become ungley no agian because it remain in the form of 2^a * 3^b * 5^c only the power is increase 
  ex:
  1 ->2=2--->2=4
         2--->3=6
         2--->5=10
    ->3=3--->2=6
         3--->3=9
         3--->5=15
    ->5=5  and so on
    1st ugley no is =1
1*2=2x   1*3=3x  1*5=5 -> till here 2 is minimu so, 2 is 2nd ugley no now start with 2
2*2=4x   2*3=6  2*5=10 ->till here 3 is minimu so, 3 is 3rd ugley no now start with 3
3*2=6   3*3=9  3*5=15 ->till here 4 is minimu so, 4 is 4rth ugley no now start with 4
and so on ...
*/
int nthUglyNumber(int n){
    vector<int>arr(n+1);
    // arr[i]=ith ugley numbers , arr[n]=nth ugley numbers return it
    int i2, i3,i5;
    i2=i3=i5=1;
    arr[1]=1 //1st ugly number
    for(int i=2;i<=n;i++){
        int i2uglynum=arr[i2]*2;
        int i3uglynum=arr[i3]*3;
        int i5uglynum=arr[i5]*5;
        int minuglynum=min({i2uglynum,i3uglynum,i5uglynum});
        arr[i]=minuglynum;
        if(minuglynum==i2uglynum) 
           i2++;
        if(minuglynum==i3uglynum)
           i3++;
        if(minuglynum==i5uglynum) 
           i5++;
    }
    return arr[n];
}

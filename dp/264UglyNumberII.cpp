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

class Solution {
public:
    unordered_map<int, unordered_map<int, double>> dp; // Use a hash map for memoization
    double serve(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5; // Case when both are empty
        if (a <= 0) return 1.0;           // Case when soup A is empty
        if (b <= 0) return 0.0;           // Case when soup B is empty

        if (dp[a][b] > 0) return dp[a][b]; // Use memoized result if available
      
        double Probability = 0.0;
        Probability += 0.25 * serve(a - 100, b);
        Probability += 0.25 * serve(a - 75, b - 25);
        Probability += 0.25 * serve(a - 50, b - 50);
        Probability += 0.25 * serve(a - 25, b - 75);
        return dp[a][b] = Probability; // Store the result in the memoization table
    }
    double soupServings(int n) {
        if (n >= 5000) return 1.0; // For very large n, the probability approaches 
        return serve(n,n);
    }
};

#include <iostream>
using namespace std;

long long maxSubarraySum(int a[], int n){
    long long current_sum = a[0], maximum_sum = a[0]; // Initialize current_sum and maximum_sum with the first element
    for(int i = 1; i < n; i++){ // Fix the loop condition (changed "1<n" to "i < n")
        current_sum = max((long long)a[i], current_sum + a[i]); // Compare current element with the sum so far
        maximum_sum = max(current_sum, maximum_sum); // Update maximum sum if needed
    }
    return maximum_sum;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << maxSubarraySum(a, n) << endl;
    return 0;
}

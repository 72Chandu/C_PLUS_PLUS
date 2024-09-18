/*Example 1: Input: n = 5 arr = {4,2,-3,1,6} Output:  Yes
Explanation: 2, -3, 1 is the subarray with sum 0.
Example 2: Input: n = 5 arr = {4,2,0,1,6} Output: Yes
Explanation: 0 is one of the element in the array so there exist a subarray with sum 0.*/
bool subArrayExists(int arr[], int n) {
    unordered_set<int> prefixSums;
    int sum = 0;
    for (int i = 0; i < n; i++) {//calculate prefix sums
        sum += arr[i]; // Accumulate the current element to sum

        // If the current sum is 0 or if it already exists in the prefix sums set, there's a zero-sum subarray
        if (sum == 0 || prefixSums.find(sum) != prefixSums.end()) {
            return true;
        }
        prefixSums.insert(sum);// Insert the current sum into the prefix sums set
    }
    return false; // If no zero-sum subarray is found, return false
}
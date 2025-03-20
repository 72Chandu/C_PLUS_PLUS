//https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&sortBy=submissions
class Solution {
  public:
    vector<int> subarraySum(vector<int>& arr, int target) {
    int left = 0, right = 0, sum = 0;
    int n = arr.size();
    while (right < n) {
        sum += arr[right];
        while (sum > target && left <= right) {
            sum -= arr[left];
            left++;
        }
        if (sum == target)  return {left + 1, right + 1}; 
        right++;
    }
    return {-1};
    }
};

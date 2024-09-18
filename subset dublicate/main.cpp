class Solution {
public:
    void f(vector<int>& nums, int n, int idx, vector<int>& current, vector<vector<int>>& res) {
        if (idx == n) {
            res.push_back(current);
            return;
        }
        // Include the current element
        current.push_back(nums[idx]);
        f(nums, n, idx + 1, current, res);
        current.pop_back();
        
        // Skip duplicates
        while (idx + 1 < n && nums[idx] == nums[idx + 1]) {
            idx++;
        }
        
        // Exclude the current element
        f(nums, n, idx + 1, current, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> current;
        f(nums, n, 0, current, res);
        return res;
    }
};
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
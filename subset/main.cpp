class Solution {
public:
    void f(vector<int>& nums, int n, int idx, vector<int>& current, vector<vector<int>>& res) {
        if (idx == n) {
            res.push_back(current);
            return;
        }
        current.push_back(nums[idx]);
        f(nums, n, idx + 1, current, res);
        current.pop_back();
        f(nums, n, idx + 1, current, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> current;
        f(nums, n, 0, current, res);
        return res;
    }
};
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
//https://leetcode.com/problems/contains-duplicate-ii/description/?envType=problem-list-v2&envId=array
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end() && i-m[nums[i]]<=k) return true;
            else m[nums[i]]=i;
        }
        return false;
    }
};
/*
Input: nums = [1,2,3,1], k = 3
i=0, lastIndex = {1: 0}
i=1, lastIndex = {1: 0, 2: 1}
i=2, lastIndex = {1: 0, 2: 1, 3: 2}
i=3, number 1 is found in lastIndex, and 3−0=3≤k, so return true.
*/

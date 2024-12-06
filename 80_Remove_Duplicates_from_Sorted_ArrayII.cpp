//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        int idx=2;
        for(int i=2;i<nums.size();i++){
            if(nums[i]!=nums[idx-2]){
                nums[idx]=nums[i];
                idx++;
            }
        }
        return idx;
    }
};

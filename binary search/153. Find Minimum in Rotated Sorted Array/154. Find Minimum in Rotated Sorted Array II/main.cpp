//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
class Solution {
public:
    int findMin(vector<int>& v) { 
        int lo = 0, hi = v.size() - 1;
            while (lo <= hi) {
                if (v[lo] <= v[hi]) return v[lo];
                int mid = lo + (hi - lo) / 2;
                if (v[mid] > v[hi]) lo = mid + 1;
                else hi=mid;
            }
        return v[lo];
    }
};

//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0;
        int hi=nums.size()-1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>nums[hi]) lo=mid+1;
            else if(nums[mid]<nums[hi]) hi=mid;
            else hi--;
        }
        return nums[lo];
    }
};
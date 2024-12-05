/*
https://leetcode.com/problems/3sum/?envType=problem-list-v2&envId=array
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue; //skip dublicate of i
            int target=-nums[i];
            int lo=i+1, hi=n-1;
            while(lo<hi){
                int sum=nums[lo]+nums[hi];
                if(sum==target){
                    ans.push_back({nums[i],nums[lo],nums[hi]});
                    while(lo<hi && nums[lo]==nums[lo+1])lo++; //skip dublicate of lo
                    while(lo<hi && nums[hi]==nums[hi-1])hi--;//skip dublicate of hi
                    lo++;
                    hi--;
                }else if(sum<target){
                    lo++;
                }else{
                    hi--;
                }
            }
        }
        return ans;
    }
};
/*
-1, 0, 1, 2, -1, -4
=
-4  -1  -1  0  1  2 
i    lo           hi

*/

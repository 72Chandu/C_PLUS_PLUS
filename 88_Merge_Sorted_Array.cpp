/*https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       for(int i=0;i<n;i++){
           nums1[m+i]=nums2[i];
       } 
       sort(nums1.begin(),nums1.end());
    }
};

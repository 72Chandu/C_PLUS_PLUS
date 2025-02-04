//https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int maxArea(vector<int>& height) {
        long ans=0;
        long lo=0, hi=height.size()-1;
        while(lo<hi){
            long h=min(height[lo],height[hi]);
            long w=hi-lo;
            ans=max(ans,h*w);
            if(height[lo]<height[hi]){
                lo++;
            }else{
                hi--;
            }
        }
        return ans;
    }
};

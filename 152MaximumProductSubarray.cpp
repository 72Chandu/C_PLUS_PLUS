//https://leetcode.com/problems/maximum-product-subarray/description/?envType=problem-list-v2&envId=dynamic-programming
class Solution { 
public:
    int maxProduct(vector<int>& nums) { //Kadane’s Algorithm for Maximum Product Subarray
        if(nums.empty()) return 0;
        int maxProd=nums[0];
        int minProd=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0) swap(maxProd,minProd);

            maxProd=max(nums[i],nums[i]*maxProd);
            minProd=min(nums[i],nums[i]*minProd);
            res=max(res,maxProd);
        }
        return res;
    }
};
/*
Initialization:
maxProd = nums[0] = 2
minProd = nums[0] = 2
result = nums[0] = 2

Index	nums[i]	maxProd Before	minProd Before	Action (if needed)	maxProd After	minProd After	result  
0	      2	     2	             2	             -	                  2	             2	                2
1	      3	     2	             2	             -	                max(3,2×3)=6	min(3,2×3)=3	    max(2,6)=6
2	     -2	     6	             3	      Swap (maxProd & minProd) 	max(-2,3×-2)=-2	min(-2,6×-2)=-12	max(6,-2)=6
3	      4	    -2	            -12	             -	                max(4,-2×4)=4	min(4,-12×4)=-48	max(6,4)=6

Time Complexity: O(N)
Space Complexity: O(1) (Constant space used)
*/

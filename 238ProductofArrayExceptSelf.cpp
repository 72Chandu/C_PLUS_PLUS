//https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int prod=1;
            for(int j=0;j<n;j++){
                if(i!=j) prod=prod*nums[j];
            }
            ans.push_back(prod);
        }
        return ans;
    }
};//give tle

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(nums.size(),1);
        int prefixProd=1;
        for(int i=0;i<nums.size();i++){
            ans[i]=prefixProd;
            prefixProd*=nums[i];
        }
        int suffixProd=1;
        for(int i=n-1;i>=0;i--){// Cal suffix prod and & multiply with prefix prod
            ans[i]*=suffixProd;
            suffixProd*=nums[i];
        }
        return ans;
    }
};
/*
nums = [1, 2, 3, 4]
ans = [1, 1, 1, 1]

i = 0:  ans[0] = prefixProd = 1
prefixProd *= nums[0] = 1 * 1 = 1

i = 1:ans[1] = prefixProd = 1
prefixProd *= nums[1] = 1 * 2 = 2

i = 2:ans[2] = prefixProd = 2
prefixProd *= nums[2] = 2 * 3 = 6

i = 3:ans[3] = prefixProd = 6
prefixProd *= nums[3] = 6 * 4 = 24

After this step, ans looks like this: [1, 1, 2, 6]

-- suffix product calculation   suffixProd=1
i = 3:ans[3] *= suffixProd = 6 * 1 = 6
suffixProd *= nums[3] = 1 * 4 = 4

i = 2:ans[2] *= suffixProd = 2 * 4 = 8
suffixProd *= nums[2] = 4 * 3 = 12

i = 1:ans[1] *= suffixProd = 1 * 12 = 12
suffixProd *= nums[1] = 12 * 2 = 24

i = 0:ans[0] *= suffixProd = 1 * 24 = 24
suffixProd *= nums[0] = 24 * 1 = 24

After this step, ans looks like this: [24, 12, 8, 6].
*/

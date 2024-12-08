//https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/?envType=daily-question&envId=2024-12-07
class Solution {
public:
    bool candivide(vector<int>& nums, int maxOperations, int mid){
        int operation=0;
        for(int balls:nums){
            if(balls>mid){
                operation+=(balls-1)/mid;
            }
            if(operation>maxOperations) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo=1;
        int hi=*max_element(nums.begin(),nums.end());
        int res=hi;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(candivide(nums, maxOperations, mid)){
                res=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return res;
    }
};
/*
[2,4,8,2]
lo=1, hi=8,res=8, mid=4 
2,4 cant split.
 8-> 4,4 (ceil(8/4)-1)= 1 operation

lo=1, hi=3,res=4, mid=2 
2,cant split.
4->2,2 (ceil(4/2)-1)= 1, 
8-> 2,2,2,2 (ceil(8/2)-1)= 3 operation
total operation=1+3=4

lo=1, hi=1,res=2, mid=1
2->1,1 (ceil(2/1)-1)= 1,
4->1,1,1 (ceil(4/1)-1)= 3, 
8-> 1,1,1,1,1,1,1 (ceil(8/1)-1)= 7 operation
2->1,1 (ceil(2/1)-1)= 1,
total operation=1+3+7+1=12 > maxoperation
*/

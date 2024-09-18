/*https://leetcode.com/problems/find-the-duplicate-number/description/
Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3*/
 

    int findDuplicate(vector<int>& nums) { // t.c=o(nlogn) s.c=o(n)
        sort(nums.begin(), nums.end());
        int i;
        for(i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) break;
        }
        return nums[i];
    }
/*
// negative marking methode 
    1 3 4 2 2    -> n+1 -> n=4
idx 0 1 2 3 4 
nums[nums[i]] -> make visited by marking -ve  i=0
    1 -3 4 2 2
idx 0 1 2 3 4 

nums[abs(nums[i])] -> make visited by marking -ve  i=1
    1 -3 4 -2 2
idx 0  1 2  3 4 

nums[abs(nums[i])] -> make visited by marking -ve  i=2
    1 -3 4 -2 -2
idx 0  1 2  3  4 

nums[abs(nums[i])] -> make visited by marking -ve  i=3
    1 -3 -4 -2 -2    
idx 0  1  2  3  4 


nums[abs(nums[i])] -> make visited by marking -ve  i=4
    1 -3 -4 -2 -2     nums[4]=-2 , nums[abs(-2)]=-4 allredy visited , so return abs(nums[i])
idx 0  1  2  3  4 
*/
int findDuplicate(vector<int>& nums) { // t.c=o(n) s.c=o(1) , array modification
    int ans=-1;
    for(int i=0;i<nums.size();i++){
        int idx= abs(nums[i])
        if(nums[idx]<0){ // allredy visited
            ans=idx;
        }else{
            nums[idx]*=-1;//make visited
        }
    }
    return ans;
}

// methode -3
/*
    1 3 4 2 2
idx 0 1 2 3 4

1 ko 1 index pe le jao
    3 1 4 2 2
idx 0 1 2 3 4

3 ko 3 index pe le jao
    2 1 4 3 2
idx 0 1 2 3 4

2 ko 2 index pe le jao
    4 1 2 3 2
idx 0 1 2 3 4

4 ko 4 index pe le jao
    2 1 2 3 4
idx 0 1 2 3 4

2 ko 2 index pe le jao, lakin 2 index pe 2 allredy hai means 2 is extra
    2 1 2 3 4
idx 0 1 2 3 4      return 2
*/
int findDuplicate(vector<int>& nums) { // t.c=o(n) s.c=o(1)
    while(nums[0]!=nums[nums[0]]){
        swap(nums[0],nums[nums[0]])
    }
    return nums[0];
}

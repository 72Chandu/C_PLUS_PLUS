//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size();i++){
            for(int j=i+1;j<numbers.size();j++){
                if(numbers[i]+numbers[j]==target){
                    return {i+1,j+1};
                }
            }
        }
        return {};
    }
};// give tle 

//methode 2 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo=0, hi=numbers.size()-1;
        while(lo<hi){
            int sum=numbers[lo]+numbers[hi];
            if(sum==target){
                return {lo+1,hi+1};
            }else if(sum<target){
                lo++;
            }else{
                hi--;
            }
        }
        return {};
    }
};

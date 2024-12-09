class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int count=0;
        int majority=0;
        for(auto& ele:m){
            if(ele.second>count){
                majority=ele.first;
                count=ele.second;
            }
        }
        return majority;
    }
};

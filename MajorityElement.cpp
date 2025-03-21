//https://www.geeksforgeeks.org/problems/majority-element-1587115620/1?page=1&sortBy=submissions
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>m;
        for(auto i:arr){
            m[i]++;
        }
        for(auto & i : m){
            if(i.second > n/2) return i.first;
        }
        return -1;
    }
};

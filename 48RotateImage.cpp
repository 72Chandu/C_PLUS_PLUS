//https://leetcode.com/problems/rotate-image/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    void rotate(vector<vector<int>>& mt) {
        int n=mt.size();
        int m=mt[0].size();
        for(int i=0;i<n;i++){ //transpose
            for(int j=i;j<m;j++){
                swap(mt[i][j],mt[j][i]);
            }
        }
        for(int i=0;i<n;i++){ //reverse each raw
            reverse(mt[i].begin(),mt[i].end());
        }
    }
};

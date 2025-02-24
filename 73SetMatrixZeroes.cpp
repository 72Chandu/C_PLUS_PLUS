//https://leetcode.com/problems/set-matrix-zeroes/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    void setZeroes(vector<vector<int>>& mt) {
        int n=mt.size();
        int m=mt[0].size();
        vector<int>row(n,1),col(m,1); //storing which row and col should be 0
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mt[i][j]==0){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]==0 || col[j]==0){
                    mt[i][j]=0;
                }
            }
        }
    }
};

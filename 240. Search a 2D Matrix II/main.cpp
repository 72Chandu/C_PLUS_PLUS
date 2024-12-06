/*
https://leetcode.com/problems/search-a-2d-matrix-ii/
1,4,7,11,15  <-
2,5,8,12,19
3,6,9,16,22
10,13,14,17,24
18,21,23,26,30              target = 5
Output: true
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();//row
        int m=matrix[0].size();//col
        int lo=0;
        int hi=m-1; //15 right-top
        while(lo<n && hi>=0){
            if(matrix[lo][hi]==target) return true;
            else if(matrix[lo][hi]>target) hi--; //move left
            else if(matrix[lo][hi]<target) lo++; //move down
        }
        return false;
    }
//https://leetcode.com/problems/sudoku-solver/description/?envType=problem-list-v2&envId=array
class Solution {
public:
    bool isvalid(vector<vector<char>>& board, int r, int c, int num){
        for(int i=0;i<9;i++){ //check for row , Each of the digits 1-9 must occur exactly once in each row.
            if(board[r][i]==num) return false;
        }
        for(int i=0;i<9;i++){ //check for column , Each of the digits 1-9 must occur exactly once in each column.
            if(board[i][c]==num) return false;
        }
        int box_r=(r/3)*3;
        int box_c=(c/3)*3;
        for(int i=0;i<3;i++){ // check for box , Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
            for(int j=0;j<3;j++){
                if(board[box_r+i][box_c+j]==num) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(isvalid(board,i,j,k)){
                            board[i][j]=k;
                            if(solve(board)) return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

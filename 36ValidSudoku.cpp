//https://leetcode.com/problems/valid-sudoku/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        for(int i=0;i<n;i++){
            unordered_set<char>rowset,colset,boxset;
            for(int j=0;j<n;j++){
                if(board[i][j]!='.' && !rowset.insert(board[i][j]).second) return false;
                if(board[j][i]!='.' && !colset.insert(board[j][i]).second) return false;
                int box_i=3*(i/3)+j/3;
                int box_j=3*(i%3)+j%3;
                if(board[box_i][box_j]!='.' && !boxset.insert(board[box_i][box_j]).second) return false;

            }
        }
        return true;
    }
};
/*
This insert method returns a pair, where:

The first element is an iterator to the inserted element (or the element that prevented the insertion).

The second element is a boolean value (true if the insertion took place, false if the element was already present in the set).
*/

//https://leetcode.com/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>copy=board;
        vector<int>neighbour={0,1,-1};
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                int liveNeighbors=0;
                for(int i=0;i<3;i++){ //counting of jinda 
                    for(int j=0;j<3;j++){
                        if(!(neighbour[i]==0 && neighbour[j]==0)){
                            int r=row+neighbour[i];
                            int c=col+neighbour[j];
                            if(r<n && r>=0 && c<m && c>=0 && copy[r][c]==1) liveNeighbors+=1;
                        }
                    }
                }
                if(copy[row][col]==1 && liveNeighbors<2 || liveNeighbors>3) board[row][col]=0;
                if(copy[row][col]==0 && liveNeighbors==3) board[row][col]=1;
            }
        }
    }
};

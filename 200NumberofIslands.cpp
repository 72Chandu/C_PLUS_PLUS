class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int,int>>q;//bfs
        int direction[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){ //not visited
                    count++;
                    q.push({i,j});
                    grid[i][j]='0'; //make visited
                    while(!q.empty()){
                        int new_i=q.front().first;
                        int new_j=q.front().second;
                        q.pop();
                        for(auto dir:direction){
                            int ni=new_i+dir[0];
                            int nj=new_j+dir[1];
                            if(ni>=0 && ni<r && nj>=0 && nj<c && grid[ni][nj]=='1'){
                                grid[ni][nj]='0';//make visited by making 1 to 0
                                q.push({ni,nj});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};

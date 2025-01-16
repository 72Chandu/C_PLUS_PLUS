//https://leetcode.com/problems/surrounded-regions/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    void bfs(vector<vector<char>>& board, int i, int j) {
        int r = board.size();
        int c = board[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        board[i][j] = 'T'; // Mark as visited and boundary-connected
        int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            int new_i = q.front().first;
            int new_j = q.front().second;
            q.pop();
            for (auto dir : direction) {
                int ni = new_i + dir[0];
                int nj = new_j + dir[1];
                if (ni >= 0 && ni < r && nj >= 0 && nj < c && board[ni][nj] == 'O') {
                    board[ni][nj] = 'T';
                    q.push({ni, nj});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        // Handle edge cases
        if (board.empty() || board[0].empty()) return;
        int rows = board.size();
        int cols = board[0].size();

        //Mark all boundary-connected 'O's as 'T'
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') bfs(board, i, 0); // Left boundary
            if (board[i][cols - 1] == 'O') bfs(board, i, cols - 1); // Right boundary
        }
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O') bfs(board, 0, j); // Top boundary
            if (board[rows - 1][j] == 'O') bfs(board, rows - 1, j); // Bottom boundary
        }

        //Flip all remaining 'O's to 'X' and restore 'T' to 'O'
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // Surrounded 'O's
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O'; // Boundary-connected 'O's
                }
            }
        }
    }
};

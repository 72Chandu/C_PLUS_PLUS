/*Input: 
grid = {{a,b,c},{d,r,f},{g,h,i}},
word = "abc"
Output: 
{{0,0}}
Explanation: 
From (0,0) we can find "abc" in horizontally right direction.
Example 2:

Input: 
grid = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}
word = "abe"
Output: 
{{0,0},{0,2},{1,0}}
Explanation: 
From (0,0) we can find "abe" in right-down diagonal. 
From (0,2) we can find "abe" in left-down diagonal. 
From (1,0) we can find "abe" in horizontally right direction.*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
bool isValid(vector<vector<char>>& grid, string word, int row, int col, int dirRow, int dirCol) {
    for (char c : word) {
        if (row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]!=c) return false;
        row += dirRow;
        col += dirCol;
    }
    return true;
}
vector<vector<int>> searchWord(vector<vector<char>>& grid, string word) {
    vector<pair<int, int>>directions={{0, 1},{0, -1},{1, 0},{-1, 0},{1, 1},{1, -1},{-1, 1},{-1, -1}};
    set<pair<int, int>> result;
    for (int row = 0; row < grid.size(); ++row) {
        for (int col = 0; col < grid[0].size(); ++col) {
            for (auto d : directions) {
                if (isValid(grid, word, row, col, d.first, d.second)) result.insert({row, col});
            }
        }
    }
    vector<vector<int>> res;
    for (auto p : result)
        res.push_back({p.first, p.second});
    sort(res.begin(), res.end());
    return res;
}
int main() {
    vector<vector<char>> grid1 = {{'a','b','c'},{'d','r','f'},{'g','h','i'}};
    string word1 = "abc";
    vector<vector<int>> result1 = searchWord(grid1, word1);
    for (auto& res : result1) {
        cout << "{" << res[0] << "," << res[1] << "} ";
    }
    cout << endl;
    vector<vector<char>> grid2 = {{'a','b','a','b'},{'a','b','e','b'},{'e','b','e','b'}};
    string word2 = "abe";
    vector<vector<int>> result2 = searchWord(grid2, word2);
    for (auto& res : result2) {
        cout << "{" << res[0] << "," << res[1] << "} ";
    }
    cout << endl;

    return 0;
}

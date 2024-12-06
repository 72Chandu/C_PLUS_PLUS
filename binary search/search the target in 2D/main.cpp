#include<bits/stdc++.h>
using namespace std;
pair<int, int> searchMatrix(vector<vector<int>>& v, int target) {
    if (v.empty() || v[0].empty())  return {-1, -1};  // Check if the matrix is empty
    int n = v.size();
    int m = v[0].size();
    int lo = 0, hi =n * m - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int x = mid / m;// Convert mid to row index
        int y = mid % m; // Convert mid to column index
        if (v[x][y] == target) return {x, y};
        else if (v[x][y] < target)  lo = mid + 1;
        else hi = mid - 1;
    }
    return {-1, -1}; // Return {-1, -1} if target is not found
}
int main() {
    vector<vector<int>> v = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 40}};
    int target = 3;
    auto indices = searchMatrix(v, target);
    if (indices.first != -1 && indices.second != -1) {
        cout << "Target found at indices: (" << indices.first << ", " << indices.second << ")" << endl;
    } else {
        cout << "Target not found" << endl;
    }
    return 0;
}

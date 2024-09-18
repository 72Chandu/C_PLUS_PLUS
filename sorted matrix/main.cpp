/* Input: N=3  Mat=[[1,5,3],[2,8,7],[4,6,9]]
Output:
1 2 3 
4 5 6
7 8 9    Explanation: Sorting the matrix gives this result.

vector<vector<int>> sortMatrix(vector<vector<int>>& matrix) {
    vector<int> flat; // Flatten the matrix into a 1D array
    for (const auto& row : matrix) {
        for (int num : row) {
            flat.push_back(num);
        }
    }
    sort(flat.begin(), flat.end());  // Sort the flattened array
    int n = matrix.size();   // Reshape the sorted array into a matrix
    int m = matrix[0].size();
    vector<vector<int>> sortedMatrix(n, vector<int>(m));
    int k = 0; // index for the flattened array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sortedMatrix[i][j] = flat[k++];
        }
    }
    return sortedMatrix;
}
*/
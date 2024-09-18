/*Input: n = 4, m = 4  M[][] = {{0 1 1 0},{1 1 1 1}, {1 1 1 1}, {1 1 0 0}}
Output: 8    For the above test case the  matrix will look like
0 1 1 0
1 1 1 1         1 1 1 1    -->area is 4 *2 = 8
1 1 1 1   ----> 1 1 1 1
1 1 0 0 

int maxArea(int M[MAX][MAX], int n, int m) {
    int maxArea = 0;
    int currArea = 0;
    vector<int> height(m, 0);// Create an array to store the heights of rectangles
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {// Update heights array based on the current row
            if (M[i][j] == 0) height[j] = 0;
            else  height[j]++;
        }
        stack<int> s;// Calculate the maximum area histogram for current row
        int left[m], right[m];
        for (int j = 0; j < m; j++) {
            while (!s.empty() && height[s.top()] >= height[j]) {
                s.pop();
            }
            if (s.empty()) left[j] = 0;
            else left[j] = s.top() + 1;
            s.push(j);
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int j = m - 1; j >= 0; j--) {
            while (!s.empty() && height[s.top()] >= height[j]) {
                s.pop();
            }
            if (s.empty()) right[j] = m - 1;
            else right[j] = s.top() - 1;
            s.push(j);
        }
        for (int j = 0; j < m; j++) {
            currArea = height[j] * (right[j] - left[j] + 1);
            maxArea = max(maxArea, currArea);
        }
    }
    return maxArea;
}
*/

int maxArea(int M[MAX][MAX], int n, int m) {
     int maxarea = 0;
    int currArea = 0;
    vector<int> height(m, 0);
    vector<int> left(m, 0); // Pre-calculate left limits
    vector<int> right(m, m - 1); // Pre-calculate right limits
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (M[i][j] == 0) height[j] = 0;
            else height[j]++;
        }
        int boundary = 0;
        for (int j = 0; j < m; j++) {
            if (M[i][j] == 0) {
                boundary = j + 1;
                left[j] = 0;
            } else {
                left[j] = max(left[j], boundary);
            }
        }
        boundary = m - 1;
        for (int j = m - 1; j >= 0; j--) {
            if (M[i][j] == 0) {
                boundary = j - 1;
                right[j] = m - 1;
            } else {
                right[j] = min(right[j], boundary);
            }
        }
        for (int j = 0; j < m; j++) {
            currArea = height[j] * (right[j] - left[j] + 1);
            maxarea = max(maxarea, currArea);
        }
    }
    return maxarea;
    }
/*M =
    1, 0, 1, 0, 1
    1, 0, 1, 1, 1
    1, 1, 1, 1, 1
    1, 0, 0, 1, 0
    
height = [1, 0, 1, 2, 1]
left  = [0, 0, 0, 3, 3]
right = [4, 4, 4, 4, 4]

    */
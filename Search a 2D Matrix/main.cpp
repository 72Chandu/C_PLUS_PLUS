/*for(int i=0;i<n;i++){   a[n][m]
    for(int j=0;j<m;j++){
        if(a[i][j]==target) return true;
    }
}
return false;
                      target=23
3  4  7  9
12 13 16 18
20 21 23 29          t=o(n)+o(log(m))
--->m
for(int i=0;i<n;i++){
    if(a[i][0]<=target && target<=a[i][m-1]){//slecting row(20 21 23 29)
        return binarySearch(a[i],target);//applay bs on 1 d array which is sorted that is (20 21 23 29)
    }
}
*/
 bool searchMatrix(vector<vector<int>>& v, int target) {
    int lo = 0;
    int hi = v.size();
    int row = 0;
    
    // Finding the row in which the target may lie using binary search
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid][0] <= target) {
            row = mid;
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    
    cout << row;
    
    // Finding the target in the selected row using binary search
    int ans = -1;
    int start = 0;
    int end = v[0].size() - 1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (v[row][mid] == target) {
            ans = mid;
            break;
        } else if (v[row][mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    return ans != -1;
}

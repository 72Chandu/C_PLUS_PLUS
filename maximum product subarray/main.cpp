/*Example 1:  Input:N = 5    Arr[] = {6, -3, -10, 0, 2}  Output: 180
Explanation: Subarray with maximum product
is [6, -3, -10] which gives product as 180.
Example 2:   Input:N = 6   Arr[] = {2, 3, 4, 5, -1, 0}    Output: 120
Explanation: Subarray with maximum product
is [2, 3, 4, 5] which gives product as 120.
------------------------- o(n^2)
int max=MAX_INT;
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
    int prod=1;
        for(int k=i;k<j;k++){
            prod=prod*arr[k];
        }
        max=max(max,prod);
    }
}
return max;
------------------------ o(n^2)
int max=MAX_INT;
   for(int i=0;i<n;i++){
    int prod=1;
    for(int j=i;j<n;j++){
    prod=prod*arr[j];
    max=max(max,prod);
    }
    
    
}
return max;
*/
long long maxProduct(vector<int> arr, int n) {
    long long prefix = 1;
    long long sufix = 1;
    long long ans = LLONG_MIN; // Initialize with LLONG_MIN
    for (int i = 0; i < n; i++) {
        if (prefix == 0) prefix = 1; // handle when prod becomes 0
        if (sufix == 0) sufix = 1;
        prefix = prefix * arr[i];
        sufix = sufix * arr[n - i - 1];
        ans = max(ans, max(prefix, sufix));
    }
    return ans;
}
#include <bits/stdc++.h>
using namespace std;
// Function to count the number of elements less than or equal to mid in both arrays
int less_than(int mid, vector<int> &arr, vector<int> &brr) {
    int count = 0;
    count += lower_bound(arr.begin(), arr.end(), mid) - arr.begin();
    count += lower_bound(brr.begin(), brr.end(), mid) - brr.begin();
    return count;
}
// Binary search to find the k-th smallest element
int bs(int n, vector<int> &arr, int k, vector<int> &brr) {
    int lo = min(arr[0], brr[0]);
    int hi = max(arr[n - 1], brr[n - 1]);
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (less_than(mid, arr, brr) < k) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}
void solve() {
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<int> arr(n), brr(m);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < m; i++)
        cin >> brr[i];
    int ans = bs(n, arr, k, brr);
    cout << ans << endl;
}
int main() {
    solve();
    return 0;
}
/*arr1[] = {2, 3, 6, 7, 9}
arr2[] = {1, 4, 8, 10}
K = 5
final_sorted = {1, 2, 3, 4, 6, 7, 8, 9 ,10} output: 7
*/
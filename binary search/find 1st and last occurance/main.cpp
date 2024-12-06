#include<bits/stdc++.h>
using namespace std;
int firstOccurrence(vector<int>& v, int target) {
    int lo = 0, hi = v.size() - 1;
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] >= target) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    return ans;
}
int lastOccurrence(vector<int>& v, int target) {
    int lo = 0, hi = v.size() - 1;
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] <= target) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int target;
    cin >> target;
    vector<int> result;
    int lb = firstOccurrence(v, target);
    if (lb == -1 || v[lb] != target) {
        result.push_back(-1);
    }
    else {
        int ub = lastOccurrence(v, target);
        result.push_back(lb);
        result.push_back(ub);
    }
    cout << result[0] << " " << result[1];
    return 0;
}
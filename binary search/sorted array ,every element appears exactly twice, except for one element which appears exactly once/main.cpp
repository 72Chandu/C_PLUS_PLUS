/*https://leetcode.com/problems/single-element-in-a-sorted-array/description/
1, a[mid]==a[mid+1]-> mid=even ,else 0
1, a[mid]=a[mid-1]->mid=odd ,else 0
index:0 1 2 3  4  5  6  
   a=[3 3 7 7 10 11 11]
      1 1 1 1 0  0   0  -> first 0 is answer
*/
#include<bits/stdc++.h>
using namespace std;

// Function to check if the middle element is a single element
bool is_mid_is_single_ele(vector<int>& arr, int mid) {
    if (mid % 2 == 0) {
        if (arr[mid] == arr[mid + 1]) return 1; 
        else return 0; 
    }
    else {
        if (arr[mid] == arr[mid - 1]) return 1; 
        else return 0;
    }
}

int main() {
    int n;
    cin >> n; // size of vector
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] = x; // storing elements in vector v at correct indices
    }
    int lo = 0, hi = n - 1;
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (is_mid_is_single_ele(v, mid)) {
            lo=mid+1;
        }
        else {
            if (mid % 2 == 1) {
                if (v[mid] == v[mid + 1]) {
                    hi = mid - 1; 
                }
                else {
                    ans=mid; break;
                }
            }
            else {
                if (v[mid] == v[mid - 1]) {
                    hi = mid - 1; 
                }
                else {
                    ans=mid; break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
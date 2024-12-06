/* methode 1:
  6   7   8   1   2   3   4   5 
 ------------     -------------
 bs1(lo->min)     bs2(min->hi) 
---------------------------------
           bs3
methode 2: -> sort array->applay bs
methode 3:
 ------------------     -------------------
 lo   tar   mid   hi    lo   mid   tar   hi
*/
#include<bits/stdc++.h>
using namespace std;
int binarySearchRotatedSorted(vector<int>& v, int target) {
    int lo = 0, hi = v.size() - 1;
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == target) {
            ans = mid;
            break; // Found the target, exit the loop
        }
        if (v[mid] >= v[lo]) {
            if (target >= v[lo] && target < v[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        } else {
            if (target > v[mid] && target <= v[hi]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    return ans;
}
int main() {
    vector<int> v = {6, 7, 8, 1, 2, 3, 4, 5};
    int target;
    cin >> target;
    cout << "at index: " << binarySearchRotatedSorted(v, target);
    return 0;
}
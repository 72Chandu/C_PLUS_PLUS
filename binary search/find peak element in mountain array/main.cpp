/*mountain array-> a[0]<a[1]<a[2]----a[i-1]<a[i]>a[i+1]---->a[n]

       c
      /\
  a /   \ b
  /      \
/         \
 a-> a[i]<a[i+1]  increasing 
 C-> PEAK a[i-1]<a[i]>a[i+1]
 b-> a[i]>a[i+1]  decreasing
 
 a[mid]>a[mid+1]->b -> mid may or may not be the peak element
  a[mid]<a[mid+1]->a -> mid  not be the peak element -> l0=mid+1
  
  m-2
  int lo = 0, hi = v.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid]<v[mid+1]) { 
            lo=mid+1
        } else{
            hi=mid;
        }
    }
    return lo;
  
*/
#include<bits/stdc++.h>
using namespace std;
int peakElement(vector<int>& v) {
    int lo = 0, hi = v.size() - 1;
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if ((mid==0||v[mid]>v[mid-1])&&(mid==v.size()-1||v[mid]>v[mid+1])) { // If the current element is greater than its neighbors, it's a peak
            ans = mid;
            break;
        } else if (mid > 0 && v[mid - 1] > v[mid]) { // If the left neighbor>>->move left
            hi = mid - 1;
        } else {     // If the right neighbor >>->move right
            lo = mid + 1;
        }
    }
    return ans;
}
int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 3, 2, 0};
    cout << "Peak element at index: " << peakElement(v);
    return 0;
}

#include<iostream>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v = {2, 5, 5, 5,5,5,6, 6,6,6,6, 8, 9, 9, 9};
    int lo = 0, hi = v.size() - 1;
    int ans = -1;
    int  x;
    cin >> x;
   
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == x) {
            ans = mid;//  probability that the x present before mid,|| we can not move after mid because it will never be the first occurance
            hi = mid - 1;
        }
        else if (v[mid] < x) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << ans<<endl;
    
    
    auto ans2=lower_bound(v.begin(), v.end(), x);//for compitative 
    cout<<ans2-v.begin()<<endl;
    return 0;
}



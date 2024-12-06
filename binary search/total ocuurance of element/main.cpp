#include<iostream>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v = {2, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 8, 9, 9, 9};
    int  x;
    cin >> x;
    auto ans1=upper_bound(v.begin(), v.end(), x);//for compitative 
    auto ans2=lower_bound(v.begin(), v.end(), x);
    cout<<((ans1-v.begin() )- (ans2-v.begin()) +1)<<endl;
    return 0;
}




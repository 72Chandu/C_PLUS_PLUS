#include<iostream>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v = {2, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 8, 9, 9, 9};
    int  x;
    cin >> x;
    auto ans2=upper_bound(v.begin(), v.end(), x);//for compitative 
    cout<<ans2-v.begin()<<endl;
    return 0;
}




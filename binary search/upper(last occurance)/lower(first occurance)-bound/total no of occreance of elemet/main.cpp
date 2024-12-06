#include <bits/stdc++.h>
using namespace std;
#include<algorithm>
int main(){
    vector<int> v{ 1,5,5,5,5,6,6,6,6,20, 30, 40, 50 };
    auto upper = upper_bound(v.begin(), v.end(), 5);
    auto lower = lower_bound(v.begin(), v.end(), 5);
 
    cout << "upper_bound for element 5 is at position : "<< (upper - v.begin()-1)<<endl;
    cout << "lower_bound for element 5 is at position : "<< (lower - v.begin())<<endl;
    cout<<"total number of occurance of 5 is "<<(upper - v.begin()-1) -  (lower - v.begin()) +1<<endl;
 
    return 0;
}
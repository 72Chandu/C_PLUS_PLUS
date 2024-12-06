/*root(x) belong to [1,x]  (i^2<=x) x=40 2^2<=40 3^2<=40 4^2<=40 5^2<=40 6^6=40 7^7>40-x */
#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin>>x;
    int lo=1, hi=x;
    int ans=0;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(mid*mid<=x){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
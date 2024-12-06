#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v{0,0,0,0,0,1,1,1,1};//array are monotonically non-decreasing, so we can apply bs
    int lo=0;
    int hi=v.size()-1;
    int ans=0;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid]==0){//yedi 0 mila then it means 1 agge milega
            lo=mid+1;
        }
        else{//means it satisfy that we encounter the 1st 1
            ans=mid;
            hi=mid-1;
        }
    }
    cout<<ans;

}
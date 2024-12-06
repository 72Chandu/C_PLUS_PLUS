#include<bits/stdc++.h>
using namespace std;
int findpeak(vector<int>&v){
    int lo=0, hi=v.size()-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(mid==lo){
            if(v[mid]>v[mid+1]) return 0;
            else return 1;
        }
        else if(mid==hi){
            if(v[mid]>v[mid-1]) return hi;
            else return hi-1;
        }
        else{
            if(v[mid]>v[mid+1] && v[mid]>v[mid-1]) return mid;
        }
        else if(v[mid]>v[mid-1]){
            lo=mid+1;
        }
        else hi=mid-1;
    }
    return -1;
}
int main(){
    vector<int>v={1,2,1,3,6,10,3};
    cout<<findpeak(v);
}
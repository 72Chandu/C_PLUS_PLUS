#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>&v,int x){
    int lo=0;//starting of search space
    int hi=v.size()-1;//end of search space
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid]==x){
            return mid;
        }
        else if(v[mid]<x){
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return -1;
}
int main(){
    vector<int>v{2,4,5,7,15,24,45,50};
    int target=15;
    cout<<binarySearch(v,target);
    return 0;
}
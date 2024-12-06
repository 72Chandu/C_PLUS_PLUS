/*   v[hi]<[lo]-> condition of sorted rotated array ---->(1) l0=0 hi=n-1;
     case 1:
       v[mid]<v[lo]-> condition arises -------(2)
       from 1 & 2 --> ele must be in b/w [lo,mid-1] ex:(4 5 6 7 2 3) -> mid=6 lo=4
    case 2:
       v[mid]>v[lo]-> condition arises -------(3)
       from 1 & 3 --> ele must be in b/w [mid+1,hi]  ex:(7 2 3 4 5 6)-> mid=3 lo=2
*/
#include<bits/stdc++.h>
using namespace std;
int findMinEle(vector<int>v){
    int lo=0, hi=v.size()-1;
    int ans=-1;
    if(v[lo]<v[hi]){
        return lo;
    }
    else{
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(v[mid]>v[mid+1] && mid+1<=hi) ans=mid+1; // (4, 5 ,6 ,[7 ,2] ,3) if mid->7
            if(v[mid]<v[mid-1] && mid-1>=lo) ans=mid; // if mid->2
            if(v[mid]>v[lo]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<"index is: "<<findMinEle(v);
    return 0;
}

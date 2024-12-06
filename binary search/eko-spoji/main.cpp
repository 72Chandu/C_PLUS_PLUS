//https://www.spoj.com/problems/EKO/
/*
brute force
20 15 10 17   m=7 (need)   to find sawblades height
sh=1  20-1 + 15-1 + 10-1 +17-1  = 58
sh=2  20-2 + 15-2 + 10-2 +17-2  =54
.
.
sh=15   20-15 + 15-15 + 10-15(neglate) +  17-15=5+0+0+2=7
optimise
0---------------20(max height of tree)
lo              hi  mid=10 ??>=7 meter ki wood milega  20-10 + 15-10 + 10-10 + 17-10 =22m>=7 
(possible sol)minimize it so, ans=10 , lo=mid+1

11-------------20  mid=15 , 20-15 + 15-15 + 10-15 + 17-15 =7  ans=7 lo=mid+1;

16-------------20  mid=18 , 20-18 + 15-18 + 10-18 + 17-18 =2 2!>=7  hi=mid-1;

16-------------17  mid=16 , 20-16 + 15-16 + 10-16 + 17-16 =5  5!>=7  hi=mid-1;

lo=16 hi=15 stop cross kar raha hai
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPossibleSol(vector<long long int>tree, long long int m, long long mid){
    long long int wooCollected=0;
    for(int i=0;i<tree.size();i++){
        if(tree[i]>mid){
            wooCollected+=tree[i]-mid;
        }
    }
    return wooCollected>=m;
}
long long int maxSawbladeHeight(vector<long long int>tree, long long int m){
    long long int lo=0, hi, ans=-1;
    hi=*max_element(tree.begin(), tree.end());
    while(lo<=hi){
        long long int mid=lo+(hi-lo)/2;
        if(isPossibleSol(tree, m, mid)){
            ans=mid;
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    return ans;
}
int main(){
    long long int n, m;
    cin>>n>>m;
    vector<long long int>tree;
    while(n--){
        long long int height;
        cin>>height;
        tree.push_back(height);
    }
    cout<<maxSawbladeHeight(tree, m);
    return 0;
}
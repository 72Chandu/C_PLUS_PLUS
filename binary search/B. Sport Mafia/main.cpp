/*  https://codeforces.com/problemset/problem/1195/B
sum of n natural no= n*(n+1)/2
move to put candies in box= 1,2,3= 1+2+3=6  n candies put-> monotonic-> applay bs
eat 1 candies , candies left in box= 6-1=5
(n-a)-> no of operation in which candies is put in box
a-> no of operaton in which candies is eat from box
(n-a)*(n-a+1)/2-> no of candies left in box
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;//n=no of move k=no of candies in the box at the end
    cin>>n>>k;  
    long long lo=0, hi=n;
    while(lo<=hi){
        long long mid=lo+(hi-lo)/2;
        //cout<<lo<<" "<<hi;
        if(((n-mid)*(n-mid+1))/2-mid==k){
            cout<<mid;
            return 0;
        }
        if(((n-mid)*(n-mid+1))/2-mid<k){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return 0;        
}
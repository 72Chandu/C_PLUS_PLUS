#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;//5
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];//2 5 4 7 8
    }
    sort(a,a+n);//2 4 5 7 8
    int k;//2
    cin>>k;
    cout<<"minimum element"<<a[k-1]<<"maxmimum element"<<a[n-k];//4  7
    
}


#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a[]={1,2,3,4,5};
    int n=5;
    int k=2;
    k=k%n;
    int ans[n];
    int j=0;
    for(int i=n-k;i<n;i++){
        ans[j]=a[i];
        j++;
    }
    for(int i=0;i<=k;i++){
        ans[j]=a[i];
        j++;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
    }
    
}
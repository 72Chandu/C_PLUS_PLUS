#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int count_1=0;
    int count_2=0;
    int count_0=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            count_0++;
        }
        else if(a[i]==1){
            count_1++;
        }
        else if(a[i]==2){
            count_2++;
        }
    }
    int i;
    for(i=0;i<count_0;i++){
        a[i]=0;//filing with 0
    }
    for(i=count_0;i<count_0+count_1;i++){
        a[i]=1;//filing with 1
    }
    while(count_2--){
        a[i++]=2;
    }
    for(i=0;i<n;i++){
        cout<<a[i];
    }
}

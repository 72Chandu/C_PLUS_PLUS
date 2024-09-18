#include<iostream>
using namespace std;
int main(){
    int a[]={1,2,1,2,1,2};
    int ans=0;
    for(int i=0;i<6;i++){
        if(i%2==0){
            ans+=a[i];
        }
        else{
            ans-=a[i];
        }
    }
    cout<<ans;
}
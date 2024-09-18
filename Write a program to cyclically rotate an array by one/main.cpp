#include<bits/stdc++.h>
using namespace std;// 1 2 3 4 5-> rotate by 1-> 5 1 2 3 4
int main(){
    int t;//no of test case
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n], i;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        int last=a[n-1];//storing last element
        for(i=n-2;i>=0;i--){
            a[i+1]=a[i];//shifting  remaning element
        }
        a[0]=last;
        for(i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    // rotate(v.begin(),v.begin()+v.size()-k, v.end())-> k-> how many time rotate in right side   rotate(v.begin(),v.begin()+v.size()-k, v.end())-> for left side
    
}
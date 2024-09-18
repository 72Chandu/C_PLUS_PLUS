#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;//no of test case
    cin>>t;
    while(t--){
        int n,m;
        int a[n],b[m];
        set<int>s;//set remove the dublicate  element, alwase in sorted
        for(int i=0;i<n;i++){
            cin>>a[i];
            s.insert(a[i]);
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
            s.insert(b[i]);
        }
        cout<<s.size()<<endl;
    }
    return 0;
}

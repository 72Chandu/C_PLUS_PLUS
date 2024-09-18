#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int min_ele=INT_MAX;
    int max_ele=INT_MIN;
    for(int i=0;i<n;i++){
        if(min_ele>a[i]){
            min_ele=a[i];
        }
    }
    for(int i=0;i<n;i++){
        if(max_ele<a[i]){
            max_ele=a[i];
        }
    }
    cout<<max_ele<<min_ele;
}//t: o(n)  sp:o(1)
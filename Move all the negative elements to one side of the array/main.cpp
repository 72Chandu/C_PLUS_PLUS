#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;//5
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    /*sort(a,a+n);  // methode 1
     for(int i=0;i<n;i++){
        cout<<a[i];
    }*/
    // int j=0;    // methode 2
    // for(int i=0;i<n;i++){
    //     if(a[i]<0){
    //         swap(a[i],a[j]);
    //         j++;
    //     }
    // }
    
    // dutch national flag algorithum (2 pointer approach) m-3 t.c=o(n)  s.c=o(1)
    // smillar approach for sorting 0 and 1
    int lo=0;//maintain the -tve no
    int hi=n-1;//maintain the +tve no
    while(lo<hi){
        if(a[lo]<0){
            lo++;
        }else if(a[h]>0){
            h--;
        }else{
            swap(a[l], a[h]);
        }
    }
    for(int i=0;i<n;i++){
            cout<<a[i];
    }
    
}





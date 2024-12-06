#include<iostream>
using namespace std;
int bs(int a[], int lo, int hi, int x){
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(a[mid]==x){
            return mid;
        }
        else if(x>a[mid]){
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    return -1;
}
int expSearch(int a[], int n, int x){
    if(a[0]==x){
        return 0;
    }
    int i=1;
    while(i<n && a[i]<=x){
        i=i*2;
    }
    return bs(a,i/2, min(i,n-1), x);
}// run 2^m times , t.c=o(log m)
/*  3,4,5,6,11,13,14,15,56,70
      i i    i           i
             i<=13       stop 56<=13
search in  interval , manly for large array
sub array is interval of 2 ka multiple
size of subarray= 2^log m - 2^log m -1 = 2^log m-1
t c(bs)=o(log(n))=o(log(2^log m-1))

application 
1. search in infinite array (unbounded array)
2.
*/
int main(){
    int a[]={3,4,5,6,11,13,14,15,56,70};
    int n=sizeof(a)/sizeof(int);
    int x=13;
    int ans=expSearch(a,n,x);
    cout<<ans;
    return 0;
}
/*
i=0 j=1;
while(a[j]<x){
    i=j;
    j=j*2;
}
 1 2 3 4 5 6 7  9 10 11 ......infinite   x=6;
 i j
   i j
     i   j
         i      j
  intial index  final index
  now you can applay bs
 
*/
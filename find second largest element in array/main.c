#include<stdio.h>
#include<limits.h>
int main(){
    int a[7]={1,2,3,4,5,6,7};
    int n=7;
    int max=INT_MIN;
    int smax=INT_MIN;
    for(int i=0;i<n;i++){//finding first max ele
        if(max<a[i]){
            max=a[i];
        }
    }
    for(int i=0;i<n;i++){ //finding second max
        if(a[i]!=max && smax<a[i]){
            smax=a[i];
        }
    }
        printf("%d",smax);
    return 0;
}
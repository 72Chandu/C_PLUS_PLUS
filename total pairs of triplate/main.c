#include<stdio.h>
int main(){
    int a[8]={7,2,4,3,8,1,6,5};
    int n=8;
    int target=9;
    int totalpairs=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]+a[j]+a[k]==target){
                    totalpairs++;
                }
            }
        }
    }
    printf("%d",totalpairs);
}
#include<stdio.h>
int main(){
    int a[7]={7,2,4,3,8,1,6};
    int targetSum=9;
    int totalPairs=0;
    for(int i=0;i<7;i++){
        for(int j=i+1;j<7;j++){
            if(a[i]+a[j]==targetSum){
                totalPairs++;
            }
        }
    }
    printf("%d",totalPairs);
}
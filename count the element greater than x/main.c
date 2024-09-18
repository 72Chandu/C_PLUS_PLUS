#include<stdio.h>
int main(){
    int a[7]={1,2,3,4,5,6,7};
    int x=5;
    int count=0;
    for(int i=0;i<7;i++){
        if(a[i]>x){
            count++;
        }
    }
    printf("%d",count);
}
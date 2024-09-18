#include<stdio.h>
int main(){
    int i,sum=0,a[5];
    printf("enter the element in array");
    for(i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    int max=a[0];
    for(i=0;i<5;i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    printf("%d",max);
    return 0;
}
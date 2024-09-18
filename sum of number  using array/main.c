#include<stdio.h>
int main(){
    int i,sum=0,a[10];
    float av;
    printf("enter the array");
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<10;i++){
        sum=sum+a[i];
        av=sum/10;
    }
    printf("sum=%d",sum);
            printf("average=%.2f",av);
    return 0;
}
#include<stdio.h>
int main(){
    int n;
    printf("enter the size of array");
    scanf("%d",&n);
    int a[n];
    int sum=0;
    printf("enter the element in array");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum=sum+a[i];
    }
    printf("%d",sum);
}
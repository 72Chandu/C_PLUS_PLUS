#include<stdio.h>
int main(){
    int n;
    printf("enter the size of array");
    scanf("%d",&n);
    int a[n];
    printf("enter the element");
    int max=-1;//sabse chota number
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    printf("%d",max);
    
}
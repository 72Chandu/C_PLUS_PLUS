#include<stdio.h>
int main(){
    int a,b,c;
    printf("enter a");
    scanf("%d",&a);
    printf("enter b");
    scanf("%d",&b);
    printf("enter c");
    scanf("%d",&c);
    if(a>b && a>c){
        printf("a is largest=%d",a);
    }
    else if(b>a && b>c){
        printf("b is largest=%d",b);
    }
    else{
        printf("c is largest=%d",c);
    }
    return 0;
}
#include<stdio.h>
int main(){
    int n1,n2;
    char op;
    printf("enter n1");
    scanf("%d",&n1);
    printf("enter n2");
    scanf("%d",&n2);
    printf("enter the operator(+,-,/,*,%)");
    scanf("%c",&op);
    switch(op){
    case '+': printf("%d",n1+n2);
    break;
    case '-':printf("%d",n1-n2);
    break;
    case'*':printf("%d",n1/n2);
    break;
    case '/':printf("%d",n1%n2);
    break;
    case'%':printf("%d",n1*n2);
    break;
    default:printf("end");
    break;
    }
    return 0;
    
}
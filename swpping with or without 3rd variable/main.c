#include<stdio.h>
int main(){
    int a=2,b=3,c;
    printf("a befor swaping=%d\n",a);
    printf("b befor swaping=%d\n",b);
    //with third variable
    c=a;
    a=b;
    b=c;
    //without third variable
    a=a+b;//2+3
    b=a-b;//5-3
    a=a-b;//5-2
    printf("a after swaping=%d\n",a);
    printf("b after swaping=%d\n",b);
    return 0;
}
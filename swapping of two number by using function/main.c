#include<stdio.h>
void swap(int x,int y){
    int temp;
    temp=x;
    x=y;
    y=temp;
    printf("after swaping a  %d",x);
     printf("after swaping b %d",y);
}
int main(){
    int a,b;
    printf("enter a");
    scanf("%d",&a);
    printf("enter b");
    scanf("%d",&b); 
    swap(a,b);//sawaping without using pointer by call by refrence
               //adrress of first element get pass as a argument in function.
               //address of first element = address of array.
}

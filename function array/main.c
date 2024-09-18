#include<stdio.h>
int fun(int x[]){//it is same array only name is chage
    x[0]=9;
    return;
}
int main(){
    int a[6]={1,2,3,4,5,6};
    fun(a);//pass by refrance
    for(int i=0;i<6;i++){
        printf("%d",a[i]);
    }
    return 0;
}
#include<stdio.h>
#include<stdbool.h>
int main(){
    int a[7]={1,2,3,4,5,6,7};
    int x=6;
    int idx=-1;
    bool flag=false;
    for(int i=0;i<6;i++){
        if(a[i]==x){
            flag=true;
            break;
        }
    }
    if(flag==false){
        printf("%d not present",x);
    }
    else{
        printf("%d present",x);
    }
    return 0;
}
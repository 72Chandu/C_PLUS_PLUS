#include<stdio.h>
#include<stdbool.h>
int main(){
    int a[7]={1,2,3,4,1,2,3};
    for(int i=0;i<=6;i++){
        bool flag=false;
        for(int j=i+1;j<=6;j++){
            if(a[i]==a[j]){
               flag=true;
            }
        }
        if(flag==false){
            printf("%d",a[i]);
            break;
        }
    }
    return 0;
}
#include<stdio.h>
int main(){
    int n;
    printf("enter the order");
    scanf("%d",&n);
    printf("enter the element in matrix");
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    } 
    //wave print:-colume wise  i=row j=col
        for(int j=0;j<n;j++){                //inpute   output          
            if(j%2==0){                      //123      741
                for(int i=n-1;i>=0;i--){     //456  =>  258
                    printf("%d",a[i][j]);    //789      963
                }
            }
            else{
                for(int i=0;i<n;i++){
                    printf("%d",a[i][j]);
                }
            }
            printf("\n");
        }
}    
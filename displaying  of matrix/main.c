#include<stdio.h>
int main(){
    int n,m,i,j;
    printf("enter the order of matrix");
    scanf("%d%d",&n,&m);
    int a[n][m];
    printf("enter the element in array");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
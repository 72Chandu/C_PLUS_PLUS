#include<stdio.h>
int main(){
    int n,m;
    printf("enter the order of matrix");
    scanf("%d %d",&n,&m);
        int a[n][m];
        int b[n][m];
        int res[n][m];
//taking input row wise is best way:-element fill row wise in matrix
//for colume wise:change(n=m,m=n,&a[i][j]=&a[j][i])onely in input loop:-element fill colume wise in matrix
        printf("enter the element in matrix a\n");
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("enter the element[%d][%d]=",i,j);
                scanf("%d",&a[i][j]);
            }
        }
        printf("enter the element in matrix b\n");
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("enter the element[%d][%d]=",i,j);
                scanf("%d",&b[i][j]);
            }
        }
        printf("matrix a\n");
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
         printf("matrix b\n");
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("%d ",b[i][j]);
            }
            printf("\n");
        }
        printf("sum of matrix\n");//logic of addition
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j]=a[i][j]+b[i][j];
                printf(" %d",res[i][j]);
            }
            printf("\n");
        }
}
/*
int arr[2][3][4]:-this is collection of 4 2-d array arr[2][3]
thes 2-d array will be converted into 1-d array with 6 element

int arr[2][3][4][5]:-this is collection of 5 3-d array arr[2][3][4]
a[2][3][4] this is collection of 4 2-d array arr[2][3]
 the 2-d array will be converted into 1-d array with 6 element
*/
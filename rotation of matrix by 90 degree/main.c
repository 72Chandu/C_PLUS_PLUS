//rotate matrix 90 degree clockwise in place
//original->transpose->reverse-each row
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
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf(" %d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //transpose by swapping in place
     for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            int temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
    }
     //output of transpose
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("transpose \n %d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //rotation by swapping transpose's matrix row element
    for(int i=0;i<n;i++){
        int j=0;
        int k=n-1;
        while(j<k){     //swapping row element
            int temp=a[i][j];
            a[i][j]=a[j][k];
            a[j][k]=temp;
            j++;
            k--;
        }
    }
    printf("\n");
    //output after rotation
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("arter rotation\n %d",a[i][j]);
        }
        printf("\n");
    }
}
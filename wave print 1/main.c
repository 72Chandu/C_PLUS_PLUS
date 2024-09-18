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
    //wave print:- row wise
    for(int i=0;i<n;i++){               //inpute   output        
        if(i%2==0){                     //123      123
             for(int j=0;j<n;j++){      //456  =>  654     
               printf("%d",a[i][j]);    //789      987
            }
        }
        else{
            for(int j=n-1;j>=0;j--){
            printf("%d",a[i][j]);
           }
        }
        printf("\n");
    }
    
}    
/*
//wave print a matix
1 2 3 4
5 6 7 8
9 10 11 12
0/p=1 5 9 6 2 7 11 12 8 4
 col=> 0   1   2   3 
      t-b b-t t-b b-t

void waveprint(vector<vector<int>>v){
    int m=v.size();
    int n=v[0].size();
    for(int i=0;i<n;i++){
        if(i & 1==0){// even no of col top to bottom
            for(int j=0;j<m;j++){
                cout<<v[i][j]<<" ";
            }
        }
        else{// bottom to top
            for(int i=m-1;i>=0;i--){
                cout<<v[i][j]<<" ";
            }
        }
    }
}


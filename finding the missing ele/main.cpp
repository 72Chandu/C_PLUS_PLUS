#include<stdio.h>
int main(){
    int a[9]={1,2,3,4,5,6,7,8};
    int n=9;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+a[i];
    }
    int sum2=n*(n+1)/2;
    int x=sum2-sum;
    printf(" missing element is %d",x);
    
}
// missing element from an array with duplicate
#include<bits/stdc++.h>
using namespace std;
void missing_number(int *a , int n){
    for(int i=0;i<n;i++){   // t.c=o(n), s.c=o(1)
        int indx=abs(a[i]);
        if(a[indx-1]>0){//visite it
            a[indx-1]*=-1;
        }
    }// -1 3 -5 -3 -4
    for(int i=0;i<n;i++){
        if(a[i]>0){
            cout<<i+1;//2
        }
    }
}
int main(){
 int a[]=[1 ,3, 5, 3, 4]
}
/*

    1 3 5 3 4
idx 1 2 3 4 5
    i

    -1 3 5 3 4
idx 1  2 3 4 5
       i

    -1 3 -5 3 4
idx 1  2 3 4 5
         i

   -1 -3 -5 3 -4
idx 1  2  3 4  5
            i -> at index 3 it is allredy visited means 3 is 2 times
           

*/
// shorting and swaping
a=[1 3 5 3 4] mission is to move the element to their respective index
   1 2 3 4 5
a=[1 3 3 4 5] 
   1 2 3 4 5   at i=2 ele=3 is mismatch so, the i=2 is missing number

int i=0;
while(i<n){
    int idx=a[i]-1;
    if(a[i]!=a[idx]){
        swap(a[i],a[idx]);
    }else{
        i++;
    }
}
// 1 3 3 4 5  -> 2 is missing 
   1 2 3 4 5
for(int i=0;i<n;i++){
    if(a[i]!=i+1){
        cout<<i+1;// printing missing number
    }
}
// geegs for geek   first repeating element 
1 5 3 4 3 5 6
0 1 2 3 4 5 6



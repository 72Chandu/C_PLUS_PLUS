/*  1  2  3  4   n->r=5  lo=0, hi=total element= n*m-1=20-1=19
    5  6  7  8    m->c=4   mid=0+19/2=9  ->10
    9 10 11 12   i,j ->c*i+j memory pe store hoga 
    13 14 15 16  c*i+j -> i=mid/c =9/4=2 , j=mid%c=9%4=1 -> by this we get the location of 10 that isa[2][1]
    17 18 19 20
*/
#include<iostream>
using namespace std;
int main(){
   int a[5][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    int lo=0;
    int cols=4;
    int row=5;
    int hi=row*cols-1;
    int target=9;
    bool flag=false;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        int r=mid/cols;
        int c=mid%cols;
        if(a[r][c]==target){
            flag=true;
            cout<<r<<","<<c<<"="<<a[r][c]<<endl;
            break;
        }else if(a[r][c]>target){
            hi=mid-1;
        }else if(a[r][c]<target){
            lo=mid+1;
        }
    }
    if(flag==true) cout<<"found";
    else cout<<"not found";
}
/* nearly sorted means the element which should be at ith index that element may found at 
idex i-1, i, i+1

  nearly sorted array= 10 3 40 20 50 80 70
                        0 1  2  3  4  5  6 
  sorted array= 3 10 20 40 50 80 70
                0 1  2  3  4  5  6 
 3-> may found at 0 ,-1, 1 in nearly sorted array, found at=1
 10-> may found at 1,0,2 in nearly sorted array, found at=0
 similarly for all
 
 target=40 
 m1-> linear search tc=o(n)
 m2->sort(tc=o(nlogn)) then bs(o(logn)) -> overall tc=o(nlogn)
*/
#include<iostream>
using namespace std;
int bs_in_nearlySortedArray(int a[], int n, int target){
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(a[mid]==target){
            return mid;
        }else if(a[mid-1]==target && mid-1>=lo){//mid-1>lo ->edge case not to move below 0 index
            return mid-1;
        }else if(a[mid+1]==target && mid+1<=hi){//mid+1<=hi -> edge case , not move away from nth index
            return mid+1;
        }else if(target<mid){
            hi=mid-2;// if I check at mid-1 above ,so we have to check from mid-2
        }else if(target>mid){
            lo=mid+2;// if I check at mid+1 above ,so we have to check from mid+2
        }
    }
    return -1;
}
int main(){
    int a[]={10 ,3 ,40 ,20 ,50 ,80 ,70};
    int n=sizeof(a)/sizeof(a[0]);
    int target=40;
    int index=bs_in_nearlySortedArray(a,n,target);
    cout<<index;
}
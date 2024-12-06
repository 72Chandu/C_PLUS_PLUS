#include<iostream>
using namespace std;
int solve(int dividend, int divisor){
    int lo=0;
    int hi=abs(dividend);
    int quitent=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(abs(divisor*mid)>dividend){
            hi=mid-1;
        }else if(abs(divisor*mid)<=dividend){
            quitent=mid;
            lo=mid+1;
        }
    }
    if((divisor<0 && dividend<0)||(divisor>0 && dividend>0)){
        return quitent;
    }else{
        return -quitent;
    }
    
}
int main(){
    int dividend=22;
    int divisor=-7;
    int ans =solve(dividend, divisor);
    cout<<ans<<endl;
    
    int precision;
    cout<<"enter the no you want after dout: ";
    cin>> precision;
    double step=0.1;
    double finalans=ans;
    for(double i=1;i<=precision;i++){
        for(double j=finalans; j*divisor<=dividend;j+=step){
            finalans=j;
        }
        step=step/10;// 0.01->0.001 ->0.001
    }
    
    cout<<"final answer:"<<finalans;
   
}
/*
dividend=10 , divisor=2 , quotient=? =5  10/2=5
dividend= divisor * quotient +remainder

dividend=>divisor * quotient

quotient must belong from 0 to dividend (0 to 10)
  
  0      5       10  mid is our quitent 
  lo     mid     hi -> 5*2<=10 -> true return mid
  ex: 22/7  d=22  div=7 
  
  0      11      22
  lo     mid      hi -> 11*7<=22 false, 77>22  hi=mid-1
  
  0       5      10
  lo      mid     hi -> 5*7<=22 false , 35>22, hi=mid-1
  
  0        2      4
  lo       nid    hi -> 2*7<=22, true,ans=2, 14<22 lo=mid+1
  
  3          4
  lo        hi -> 3*7<=22, true ans=3, lo=mid+1  
  mid
  4 lo,hi,mid -> 4*7<=22 false , hi=mid+1 we do not cross the lo and hi
*/

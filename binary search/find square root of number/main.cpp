/*
square root(10) -> must be from 0 to 10
   0 1 2 3 4 5 6 7 8 9 10
   l         m          hi  5*5=25>10 so move left
    m=2 -> 2*2=4 <10 move right   ans=2
    m=3 -> 3*3=9 <10 move right   ans=3
    m=4-> 4*4=16 >10  move left
    
    how 3.16
    3.1 ->3.1*3.1<=10
    3.2 ->3.2*3.2>=10 ->not a answer below it aslo not a answer
    3.3
    
    3.9  -> obsebation -> 0.1 is added in each step, if we want 1 precision digits
    
    -------- ->3.1+0.01->3.11
    
    3.11 -> 3.11*3.11<=10
    3.12 ->3.12*3.12<=10
    3.13 ->3.13*3.13<=10
    3.14 ->3.14*3.14<=10
    3.15 ->3.15*3.15<=10
    3.16 ->3.16*3.16<=10
    3.17 ->3.17*3.17>10  -> false 
    3.18
    3.19   -> obserbation-> 0.01 is added in each step , if we want 2 precision digits
    for more decimal we do same as above
*/
#include<iostream>
using namespace std;
int findsqrt(int n){
    int lo=0, hi=n;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(mid*mid==n){
            return mid;
        }else if(mid*mid>n){
            hi=mid-1;
        }else if(mid*mid<n){
            ans=mid;
            lo=mid+1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int ans=findsqrt(n);
    cout<<ans<<endl;
    int precision;
    cout<<"enter the no you want after dout"<<endl;
    cin>> precision;
    double step=0.1;
    double finalans=ans;
    for(double i=1;i<=precision;i++){
        for(double j=finalans; j*j<=n;j+=step){
            finalans=j;
            
        }
        step=step/10;// 0.01->0.001 ->0.001
    }
    
    cout<<"final answer"<<finalans;
}
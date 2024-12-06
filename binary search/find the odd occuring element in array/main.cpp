#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>arr){
    int lo=0;
    int hi=arr.size()-1;
    while(lo<=hi){
        if(lo==hi) return lo;
        int mid=lo+(hi-lo)/2;
        if(mid%2==0){
            if(arr[mid]==arr[mid+1]){
                lo=mid + 2;
            }
            else {
                hi=mid;
            }
        }else{
            if(arr[mid]==arr[mid-1]){
                lo=mid + 1;
            }else{
                hi=mid - 1;
            }
        }
        
    }
    return -1;
}
int main(){
    vector<int>arr{1 ,1 ,2 ,2 ,3 ,3 ,4 ,4 ,3 ,600 ,600, 4 ,4 };
    int ans=solve(arr);
    cout<<ans;
}
/*all element ocuure even no of times except one all repeting occurance of elemt appeare in pair 
 and pair are not adjacent (there canot be max than 2 conscutive occurance of any element)
 find the element that appeare odd no of times
    
    1 1 2 2 3 3 4 4 3 600 600 4 4 
    
    1->2
    2->2
    3->3
    4->4
    600->2
    xor-> a^a=0, a^b=1
    1^1^2^2^3^3^4^4^3^600^600^4^4 =3 -> tc=o(n)
    
    arr=1 1 2 2 3 3 4 4 3 600 600 4  4 
    idx=0 1 2 3 4 5 6 7 8  9  10  11 12 
        e o e o e o e o e  o  e    o  e
                        |
    
    obsebation2=every first pair element is at even indec, and other at odd index before 3(ans) after ans the first pair 
    is at odd index, other at even index-> ansewr allwase at even index
      
        even  odd  ans  odd even

mid-> even
                 _         _ 
                mid  ==   mid+1 -> left me ho , move right mid+2
                even      odd
                
                  _         _ 
                mid  !=   mid+1 -> mid may be the answer or , the answer may be in left side, ->search in left lo=mid
                even      odd
                
mid-> odd
                 _         _ 
                mid-1 ==  mid -> left me ho , move right for ans -> lo=mid+1
                even      odd
                
                  _         _ 
                mid-1 !=   mid -> mid is odd so, it cant be answer , the answer is in left side, -> hi=mid-1
                even      odd
*/
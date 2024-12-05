/*str = “0100110101”   Output: 4 
The required substrings are “01”, “0011”, “01” and “01”.
Input: str = “0111100010”  Output: 3 

Input: str = “0000000000” 
Output: -1*/
#include<bits/stdc++.h>
using namespace std;
int maxsubstr(string s, int n){
    int count0=0, count1=0;//to atore the count of 0 and 1
    int cnt=0;//to store the count of maximum substrings s can be divided into
    for(int i=0;i<n;i++){
        if(s[i]=='0') count0++;
        else count1++;
        if(count0==count1){
            cnt++;
        }
    }
    if(count0!=count1) return -1; //it is not possible to split the string
    return cnt;
}
int main(){
    string s="0100110101";
    int n=s.length();
    cout<<maxsubstr(s,n);
}
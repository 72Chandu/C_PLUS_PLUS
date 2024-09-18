#include<iostream>
#include<vector>
using namespace std;
void prefixSum(vector<int>&v){
    for(int i=0;i<v.size();i++){
        v[i]=v[i]+v[i-1];
    }
    return;
}
int main(){
    vector<int>v={5,4,1,2,3};
    prefixSum(v);
    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
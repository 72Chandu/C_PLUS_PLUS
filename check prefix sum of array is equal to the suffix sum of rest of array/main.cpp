#include<iostream>
#include<vector>
using namespace std;
bool prefixSuffix(vector<int>&v){
    int total_sum=0;
    for(int i=0;i<v.size();i++){
        total_sum+=v[i];
    }
    int pre_sum=0;
    for(int i=0;i<v.size();i++){
        pre_sum+=v[i];
        int suf_sum=total_sum-pre_sum;
        if(suf_sum==pre_sum){
        return true;
        }
    }
    
    return false;
}
int main(){
    vector<int>v={6,2,4,3,1};
    cout<<prefixSuffix(v);
    
}
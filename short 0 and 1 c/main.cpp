#include<iostream>
#include<vector>
using namespace std;
void zeroOne(vector<int>&v){
    int zeor_count=0;
    for(int ele:v){
        if(ele==0){
            zeor_count++;
        }
    }
    for(int i=0;i<v.size();i++){
        if(i<zeor_count){
            v[i]=0;
        }
        else{
            v[i]=1;
        }
    }
}
int main(){
    vector<int>v={1,1,0,0,1,0,1,0};
    zeroOne(v);
    for(int i=0;i<8;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
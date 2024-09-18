#include<iostream>
#include<vector>
using namespace std;
void zeroOne(vector<int>&v){
    int leftptr=0;
    int rightptr=v.size()-1;
    while(leftptr<rightptr){
        if(v[leftptr]==1&&v[rightptr]==0){
            v[leftptr]=0;
            v[rightptr]=1;
            leftptr++;
            rightptr--;
        }
        if(v[leftptr]==0){
           leftptr++; 
        }
        if(v[rightptr]==1){
            rightptr--;
        }
    }
}
int main(){
    vector<int>v={1,1,0,0,1,0,1,0};
    zeroOne(v);
    for(int i=0;i<v.size()-1;i++){
        cout<<v[i];
    }
    return 0;
}
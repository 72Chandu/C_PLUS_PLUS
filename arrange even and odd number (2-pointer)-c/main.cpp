#include<iostream>
#include<vector>
using namespace std;
void shortByPiraty(vector<int>&v){
    int leftptr=0;
    int rightptr=v.size()-1;
    while(leftptr<rightptr){
        if(v[leftptr]%2==1&&v[rightptr]%2==0){
            swap(v[leftptr],v[rightptr]);
            leftptr++;
            rightptr--;
        }
        if(v[leftptr]%2==0){
            leftptr++;
        }
        if(v[rightptr]%2==1){
            rightptr--;
        }
    }
}
int main(){
    vector<int>v={1,2,3,4,5};
    shortByPiraty(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
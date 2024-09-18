#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void shortSquareArray(vector<int>&v){
    vector<int>ans;
    int leftptr=0;
    int rightptr=v.size()-1;
    while(leftptr<=rightptr){
        if(abs(v[leftptr])<abs(v[rightptr])){
            ans.push_back(v[rightptr]*v[rightptr]);
            rightptr--;
        }
        else{
            ans.push_back(v[leftptr]*v[leftptr]);
            leftptr++;
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    vector<int>v={-10,-3,2,5,6};
    shortSquareArray(v);
    return 0;
}
/* 3,1,2-> 3, 1, 2, 3 1, 1 2, 3 2, 3 1 2-> total 8  folow the order*/
#include<bits/stdc++.h>
using namespace std;
/*
void print(int id, vector<int>&v,int a[], int n){
    if(id==n){
        for(auto i:v){
            cout<<i<<" ";
        }
        if(v.size()==0) cout<<"{}";
        cout<<endl;
        return;
    }
    v.push_back(a[id]);//pick the particular index into subseqence
    print(id+1,v,a,n);
    v.pop_back();
    print(id+1,v,a,n);//not pick 
}

int main(){
    int arr[]={3,1,2};
    int n=3;
    vector<int>ds;
    print(0,ds,arr,n);//O(2^n*n); s=O(n);
}*/
int subseqence(string str,string op[]){
    if(str.length()==0){
        op[0]="";
        return 1;
    } 
   int smallerOutputSize=subseqence(str.substr(1), op);
   // a b c d ...  ab ac ad...
   for(int i=0;i<smallerOutputSize;i++){
       op[i+smallerOutputSize]=str[0]+op[i];
   }
   return 2*smallerOutputSize;
    
    
}
int main(){
    string output[1000];
    int outputSize=subseqence("abc", output);
    for(int i=0;i<outputSize;i++){
        cout<<output[i]<<endl;
    }
}

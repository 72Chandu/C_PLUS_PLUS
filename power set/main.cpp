/*
  0 1 2-> index of bit
s=a b c-> a,b,c,ab,ac,bc,abc   (0to 2^n-1)
  2 1 0 <-
o 0 0 0-> ""
1 0 0 1 ->a
2 0 1 0-> b
3 0 1 1-> ab
4 1 0 0 -> c
5 1 0 1 -> ac
6 1 1 0->bc
7 1 1 1-> abc */

#include<bits/stdc++.h>
using namespace std;
string print(string s , int i){    
    int j = 0;
    string sub;
    while(i>0){//finding where the bit is set
        if(i & 1){
            sub.push_back(s[j]); //pushing only when bit is set 
        }
        j++;  //always incrementing the index pointer
        i = i >> 1;
    }
    return sub;
}
vector<string> createsubsets(string& s){
    vector <string> res;
    for(int i=1;i<=((1<<s.size())-1);i++){//each time we create a subsequence for corresponding binary representation
        res.push_back(print(s,i));
    }
    return res;
}
 
int main(){
    string s = "abc";    
    vector <string> print = createsubsets(s); //vector of strings to store all sub-sequences
    for(int i = 0 ; i < print.size() ; i++){//print function
        for (int j = 0; j < print[i].size(); j++){
            cout << print[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}

//Time Complexity: O(n* 2^n)
//Auxiliary Space: O(n)
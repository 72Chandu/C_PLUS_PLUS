/*Input: ABC
Output: ABC ACB BAC BCA CAB CBA
Explanation: Given string ABC has permutations in 6  forms as ABC, ACB, BAC, BCA, CAB and CBA .*/
#include<bits/stdc++.h>
using  namespace std;
vector<string>genratePrmuation(string s){
    vector<string>permutation;
    sort(s.begin(),s.end());//sort the string to permutation in lexicographically inc order
    do{
        permutation.push_back(s);
    }while(next_permutation(s.begin(),s.end()));
    return permutation;
}
int main(){
    string s="abc";
    vector<string> perms=genratePrmuation(s);
    cout<<"permutation of "<<s<<"";
    for(const string &i:perms){
        cout<<i<<endl;
    }
}
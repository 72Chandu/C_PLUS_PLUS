//m-1
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;
    map<string,bool>m;
    for(int i=0;i<s.length();i++){
        string temp="";
        for(int j=i;j<s.length();j++){
            temp+=s[j];
            m[temp]=true;
        }
    }
    cout<<"distinct substrings are: "<<m.size()<<endl;
    return 0;
}
//O(n³) in the worst case due to: O(n²) substrings  Each insertion/compare may take up to O(n)

//m-2
/*
Step 1: Insert all suffixes of "ababa"
Suffixes of "ababa" are:   "ababa" , "baba",  "aba" , "ba",  "a"

Let’s insert and count how many new nodes are added:
Insert "ababa"
a → new node ✅
b → new node ✅
a → new node ✅
b → new node ✅
a → new node ✅
➤ 5 new nodes

Insert "baba"
b → new node ✅
a → new node ✅
b → new node ✅
a → new node ✅
➤ 4 new nodes

Insert "aba"
a → already exists
b → already exists
a → already exists
➤ 0 new nodes

Insert "ba"
b → already exists
a → already exists
➤ 0 new nodes

Insert "a"
a → already exists
➤ 0 new nodes
Total New Nodes = Distinct Substrings: 5 (from "ababa") + 4 (from "baba") = 9
Add 1 for the empty substring (optional, depending on definition)
*/
#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
    unordered_map<char,TrieNode*>children;
};
class Trie{
    public:
    TrieNode* root;
    int count;
    Trie(){
        root=new TrieNode();
        count=0;
    }
    void Insert(string s){
        for(int i=0;i<s.length();i++){
            string sub=s.substr(i);
            TrieNode* curr=root;
            for(char ch:sub){
                if(curr->children.find(ch)==curr->children.end()){
                    curr->children[ch]=new TrieNode();
                    count++; //new sunstring added
                }
                curr=curr->children[ch];
            }
        }
    }
    int noOfDistinctSubstr(){
        return count;
    }

};
int main(){
    string s;
    cout<<"enter string"<<endl;
    cin>>s;
    Trie trie;
    trie.Insert(s);
    cout<<"distinct substrings are: "<<trie.noOfDistinctSubstr()<<endl;
    return 0;
}
/*
enter string: ababa
distinct substrings are: 9
*/

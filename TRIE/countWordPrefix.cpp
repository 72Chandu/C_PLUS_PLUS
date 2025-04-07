/*
apple
app
apple
apex

wordCount: How many times a complete word ends at this node.
prefixCount: How many words pass through this node (used to count prefixes)
(root)
  |
  a (prefixCount=4)
  |
  p (prefixCount=4)
  |
  p (prefixCount=3, wordCount=1) ← 'app' ends here
  |
  ├── l (prefixCount=2)
  │   |
  │   e (prefixCount=2, wordCount=2) ← 'apple' ends here (inserted twice)
  |
  └── e (prefixCount=1)
      |
      x (prefixCount=1, wordCount=1) ← 'apex'

*/
#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
    TrieNode* children[26];
    int wordCount;
    int prefixCount;
    TrieNode(){
        wordCount=0;
        prefixCount=0;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};
class Trie{
    TrieNode* root;
    public:
    Trie(){
        root=new TrieNode();
    }
    void insert(string word){
        TrieNode* node=root;
        for(char c:word){
            int idx=c-'a';
            if(!node->children[idx]) node->children[idx]=new TrieNode();
            node=node->children[idx];
            node->prefixCount++;
        }
        node->wordCount++;
    }
    int countWordsEqualTo(string word){
        TrieNode*node=root;
        for(char c:word){
            int idx=c-'a';
            if(!node->children[idx]) return 0;
            node=node->children[idx];
        }
        return node->wordCount;
    }
    int countWordsStartingWith(string word){
        TrieNode*node=root;
        for(char c:word){
            int idx=c-'a';
            if(!node->children[idx]) return 0;
            node=node->children[idx];
        }
        return node->prefixCount;
    }
    void erase(string word){
        TrieNode* node=root;
        if(countWordsEqualTo(word)==0) return ;
        for(char c:word){
            int idx=c-'a';
            node=node->children[idx];
            node->prefixCount--;
        }
        node->wordCount--;
    }
};
int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apple");
    trie.insert("apex");

    cout << "Words equal to 'apple': " << trie.countWordsEqualTo("apple") << endl; // 2
    cout << "Words starting with 'ap': " << trie.countWordsStartingWith("ap") << endl; // 4
    cout << "Words starting with 'app': " << trie.countWordsStartingWith("app") << endl; // 3

    trie.erase("apple");
    cout << "After erasing 'apple' once..." << endl;
    cout << "Words equal to 'apple': " << trie.countWordsEqualTo("apple") << endl; // 1
    return 0;
}

//https://leetcode.com/problems/word-break/description/
class Solution {
public:
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;
        TrieNode(){
            isEnd=false;
            for(int i=0;i<26;i++){
                children[i]=nullptr;
            }
        }
    };
    class Trie{
        public:
        TrieNode* root;
        Trie(){
            root=new TrieNode();
        }
        void insert(string word){
            TrieNode* node=root;
            for(char c:word){
                int idx=c-'a';
                if(!node->children[idx]) node->children[idx]=new TrieNode();
                node=node->children[idx];
            }
            node->isEnd=true;
        }
    };
    bool dfs(string &s, int start, TrieNode* root, unordered_map<int,bool>&memo){
        if(start==s.size()) return true;
        if(memo.count(start)) return memo[start];
        TrieNode* node=root;
        for(int i=start; i<s.size();i++){
            char c=s[i];
            if(!node->children[c-'a']) break;
            node=node->children[c-'a'];
            if(node->isEnd){
                if(dfs(s,i+1,root,memo)) return memo[start]=true;
            }
        }
        return memo[start]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(string word:wordDict){
            trie.insert(word);
        }
        unordered_map<int,bool>memo;
        return dfs(s,0,trie.root,memo);
    }
};
/*
inserting 
Root
├── a
│   └── p
│       └── p
│           └── l
│               └── e (isEnd = true)
└── p
    └── e
        └── n (isEnd = true)

dfs and memo
Start at index 0 of "applepenapple"

dfs(0): check prefixes starting from index 0
  - Try: "a" → not a word yet
  - Try: "ap" → not a word yet
  - Try: "app" → not a word yet
  - Try: "appl" → not a word yet
  - Try: "apple" - word found → recurse dfs(5)

dfs(5): check prefixes from index 5
  - Try: "p" → not a word
  - Try: "pe" → not a word
  - Try: "pen" - word found → recurse dfs(8)

dfs(8): check prefixes from index 8
  - Try: "a" → not a word yet
  - ...
  - Try: "apple" - word found → recurse dfs(13)
dfs(13): index == s.size() → return true
Backtrack:
dfs(13) = true → dfs(8) = true → dfs(5) = true → dfs(0) = true Final result: true

Memoization
memo[13] = true
memo[8] = true
memo[5] = true
memo[0] = true
*/

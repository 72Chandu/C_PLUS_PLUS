/*
Insert all strings into the Trie.
Then, for each string, check if all prefixes of that string also exist in the Trie as complete words.
A complete string is one for which all its prefixes are present in the Trie as words.

"ninja" has prefixes: "n", "ni", "nin", "ninj" → all are present ✔️
"ninga" has "ning" as a prefix, which is not in the list ❌

We'll insert these words into the Trie:
"n", "ni", "nin", "ninj", "ninja", "ninga"

Root
 |
 n (isEnd) 
  |
  i (isEnd)
   |
   n (isEnd)
    |
    j (isEnd)
     | \
     a  g
    (isEnd) \
           a
         (isEnd)
n ->  i(isend=true)
n ->i n(isend=true)
n ->i->n  j(isend=true)
 n → i → n → j → a → "ninja" ✔️ (every node is isEnd = true)
 n → i → n → j → g → a → "ninga" ❌ (node "g" is not isEnd)

✅ Valid Complete Strings in Trie: "n" ,"ni", "nin", "ninj", "ninja" ✅
🔍 Result: Among valid complete strings, "ninja" is the longest.
*/
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(const string &word) {
        TrieNode* node = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool allPrefixesExist(const string &word) {
        TrieNode* node = root;
        for(char ch : word) {
            int idx = ch - 'a';
            node = node->children[idx];
            if(!node || !node->isEnd)
                return false;
        }
        return true;
    }
};

string longestCompleteString(vector<string> &words) {
    Trie trie;
    for(const string &word : words)
        trie.insert(word);

    string longest = "";
    for(const string &word : words) {
        if(trie.allPrefixesExist(word)) {
            if(word.length() > longest.length())
                longest = word;
            else if(word.length() == longest.length() && word < longest)
                longest = word;  // lexicographically smaller
        }
    }

    return (longest == "") ? "None" : longest;
}

int main() {
    vector<string> words = {"n", "ni", "nin", "ninj", "ninja", "ninga"};
    cout << "Longest complete string: " << longestCompleteString(words) << endl;
    return 0;
}
//Longest complete string: ninja

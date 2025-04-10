//leetcode
class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    class Trie {
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }
        void insert(const string& w) {
            TrieNode* node = root;
            for (char c : w) {
                int idx = c - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
            node->isEnd = true;
        }
        bool isPrefix(string& small, string& big) {
            if (small.size() > big.size()) return false;
            for (int i = 0; i < small.size(); i++) {
                if (small[i] != big[i]) return false;
            }
            return true;
        }

        bool isSuffix(string& small, string& big) {
            if (small.size() > big.size()) return false;
            for (int i = 0; i < small.size(); i++) {
                if (small[small.size() - 1 - i] != big[big.size() - 1 - i]) return false;
            }
            return true;
        }
    };

    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        Trie prefixTrie, suffixTrie;

        for (string w : words) {
            prefixTrie.insert(w);
            string rev = w;
            reverse(rev.begin(), rev.end());
            suffixTrie.insert(rev);
        }

        for (int i = 0; i < words.size(); i++) {
            string w1 = words[i];
            for (int j = i + 1; j < words.size(); j++) {
                string w2 = words[j];
                if (prefixTrie.isPrefix(w1, w2) && suffixTrie.isSuffix(w1, w2))count++; 
            }
        }
        return count;
    }
};

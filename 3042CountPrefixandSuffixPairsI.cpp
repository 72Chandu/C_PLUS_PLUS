//https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/
class Solution {
public:
    bool isPrefixAndSuffix(string &small, string &big){
        return big.substr(0,small.size())==small && big.substr(big.size()-small.size())==small;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(isPrefixAndSuffix(words[i],words[j])) count++;
            }
        }
        return count;
    }
};

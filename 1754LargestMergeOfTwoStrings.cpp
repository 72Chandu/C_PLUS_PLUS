//https://leetcode.com/problems/largest-merge-of-two-strings/description/
class Solution {
public:
    string largestMerge(string word1, string word2) {
        if(word1=="") return word1;
        if(word2=="") return word2;
        string merge="";
        while(word1.size()!=0 && word2.size()!=0){
            if(word1>word2){
                merge+=word1[0];
                word1=word1.substr(1);

            }else{
                merge+=word2[0];
                word2=word2.substr(1);
            }
        }
        while(word1.size()!=0){
            merge+=word1[0];
            word1=word1.substr(1);
        }
        while(word2.size()!=0){
            merge+=word2[0];
            word2=word2.substr(1);
        }
        return merge;
    }
};

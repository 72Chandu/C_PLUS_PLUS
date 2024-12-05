/*
https://leetcode.com/problems/longest-common-prefix/description/

Input: strs = ["flower","flow","flight"]
Output: "fl"

Input: strs = ["dog","racecar","car"]
Output: "" Explanation: There is no common prefix among the input strings.

0 flower         currchar='f'(str[0][0]) -> l
1 flow      s[1][0]==f , s[2][0]==f   ans=f
3 flight

*/
string longestCommonPrefix(vector<string>& strs){
        string ans;
        int i=0;
        while(true){
            char curr_ch=0;
            for(auto s: strs){
                if(i>=s.size()){
                    curr_ch=0; //out of bound
                    break;
                }
                if(curr_ch==0){
                    curr_ch=s[i];//f
                }else if(s[i]!=curr_ch){
                    curr_ch=0;
                    break;
                }
            }
            if(curr_ch==0){
                break;
            }
            ans.push_back(curr_ch);
            i++;
        }
        return ans;
    }

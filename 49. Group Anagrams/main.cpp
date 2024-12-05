//https://leetcode.com/problems/group-anagrams/description/
/*

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
eat,tea,tan,ate,nat,bat-> sort-> aet, aet , ant, aet ,ant, abt
map 
key   value
aet   eat, tea , aate
ant   tan , nat
abt    bat

Input: strs = [""]
Output: [[""]]

Input: strs = ["a"]
Output: [["a"]]
*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
     map<string , vector<string> >mp;
     for(auto str : strs){ 
         string s=str;//eat
         sort(s.begin(),s.end());//aet
         mp[s].push_back(str);
     }
     vector<vector<string>>ans;
     for(auto it=mp.begin(); it!=mp.end();it++){
         ans.push_back(it->second);
     }
     return ans;
}// o(n klogk) n->str.length() , k->length of largest string , s.c=o(nk)

/*   methode 2
eat,tea,tan,ate,nat,bat
hash 
1.eat    -> e->1  a->1 , t->1
2.tea     same as 1
3.tan    -> t->1   a->1  n->1
4.ate    same as 1
5.nat    same as 3
6.bat    -> b->1 a->1 t->1

hash                   vector string 
e->1  a->1 , t->1      eat, tea , ate
t->1   a->1  n->1      tan , nat 
b->1 a->1 t->1         bat
*/
std::array<int,256>hash(string s){
    std::array<int,256>hash={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]]++;
    }
    return hash;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
     map<std::array<int,256> , vector<string> >mp;
     for(auto str : strs){ 
         mp[hash(str).push_back(str);
     }
     vector<vector<string>>ans;
     for(auto it=mp.begin(); it<=mp.end();it++){
         ans.push_back(it.second);
     }
     return ans;
}//t=o(nk) , s=o(nk)
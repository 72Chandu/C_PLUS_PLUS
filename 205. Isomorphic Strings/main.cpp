/*
https://leetcode.com/problems/isomorphic-strings/description/
Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.
t.length == s.length

Input: s = "egg", t = "add"
Output: true
e->a , g->d

Input: s = "foo", t = "bar"
Output: false
f->b  o->a      o->r(nahi kar saktey hai)

Input: s = "paper", t = "title"
Output: true
p->t  a->i  e->l  r->e
*/
bool isIsomorphic(string s, string t) {
        int hash[256]={0};//mapping of each char of language 's' to language 't'
        bool istCharsMapped[256]={0}; //stores if t[i] char already mapped with s[i]
        for(int i=0;i<s.size();i++){
            if(hash[s[i]]==0 && istCharsMapped[t[i]]==0){
                hash[s[i]]=t[i];
                istCharsMapped[t[i]]=true;
            }
        }
        for(int i=0;i<s.size();i++){
            if(char(hash[s[i]])!=t[i]){
                return false;
            }
        }
        return true;
}
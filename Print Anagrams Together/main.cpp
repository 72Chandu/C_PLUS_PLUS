

bool areAnagram(const string &s1, const string& s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    unordered_map<char, int> freq;
    for(const char c: s1){ // Fix: Added 'char' before 'c'
        freq[c]++;//storing the character and frequency of character of s1
    }
    for(char c:s2){
        if(freq.find(c)==freq.end() || freq[c]==0){
            return false;//character not present in s1
        }
        freq[c]--;//decrement the count of character in s1
    }//after comparing 
    for(auto & pair: freq){
        if(pair.second!=0) return false; //even after decrement there is character means s1 character is not same as s2 character
    }
    return true;
}
vector<vector<string>> Anagrams(vector<string>& string_list) {
    vector<vector<string>> ans;
    vector<bool> visited(string_list.size(), false);

    for (int i = 0; i < string_list.size(); ++i) {
        if (!visited[i]) {
            vector<string> anagram_group;
            anagram_group.push_back(string_list[i]);
            visited[i] = true;

            for (int j = i + 1; j < string_list.size(); ++j) {
                if (!visited[j] && areAnagram(string_list[i], string_list[j])) {
                    anagram_group.push_back(string_list[j]);
                    visited[j] = true;
                }
            }
            if (anagram_group.size() > 1) {
                ans.push_back(anagram_group);
            }
        }
    }

    return ans;
}
----------------------------------------------------------------------------------------
//words[] = {act,god,cat,dog,tac}-> sort-> act,dgo,act,dgo,atc
vector<vector<string>>Anagrams(vector<string>& s){
    vector<vector<string>>ans;
    unordered_map<string, vector<string>>m;//(key,value) key can not be dublicate
    for(auto x: s){
        string temp=x;//store the current word
        sort(x.begin(),x.end());//sort the character of  each word
        m[x].push_back(temp);//{act->act, god->dgo, cat->act, dog->dgo, tac->atc}
    }
    for (auto it : m) {// Extract anagram groups from the map
            ans.push_back(it.second);
    }
    return ans;
}
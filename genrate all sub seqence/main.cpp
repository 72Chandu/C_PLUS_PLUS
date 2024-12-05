#include<bits/stdc++.h>
using namespace std;
// Function to generate all subsequences of a string
void generateSubsequences(const string& s, int index, string current, vector<string>& result) {
    if (index == s.length()) {
        if (!current.empty())
            result.push_back(current);
        return;
    }
    generateSubsequences(s, index + 1, current + s[index], result);// Include the current character
    generateSubsequences(s, index + 1, current, result);// Exclude the current character
}

int main() {
    string s = "apple";
    vector<string> subsequences;
    generateSubsequences(s, 0, "", subsequences);
    sort(subsequences.begin(), subsequences.end()); // Sort the subsequences for better readabilit
    for (const string& subseq : subsequences) {// Print all subsequences
        cout << subseq << endl;
    }
    return 0;
}

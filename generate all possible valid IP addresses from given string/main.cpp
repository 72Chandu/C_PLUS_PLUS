#include <bits/stdc++.h>
using namespace std;

int is_valid(string ip) {
    vector<string> ips;
    string ex = "";
    for (int i = 0; i < ip.size(); i++) {
        if (ip[i] == '.') {
            ips.push_back(ex);
            ex = "";
        } else {
            ex = ex + ip[i];
        }
    }
    ips.push_back(ex);

    for (int i = 0; i < ips.size(); i++) {
        if (ips[i].length() > 3 || stoi(ips[i]) < 0 || stoi(ips[i]) > 255) return 0;
        if (ips[i].length() > 1 && stoi(ips[i]) == 0) return 0;
        if (ips[i].length() > 1 && stoi(ips[i]) != 0 && ips[i][0] == '0') return 0;
    }
    return 1;
}

void convert(string ip) {
    int l = ip.length();
    if (l > 12 || l < 4) {
        cout << "Not a valid IP address" << endl;
        return;
    }
    string check = ip;
    vector<string> ans;
    for (int i = 1; i < l - 2; i++) {
        for (int j = i + 1; j < l - 1; j++) {
            for (int k = j + 1; k < l; k++) {
                check = check.substr(0, k) + "." + check.substr(k);
                check = check.substr(0, j) + "." + check.substr(j);
                check = check.substr(0, i) + "." + check.substr(i);
                if (is_valid(check)) {
                    ans.push_back(check);
                    cout << check << endl;
                }
                check = ip;
            }
        }
    }
}

int main() {
    string A = "25525511135";
    string B = "25505011535";
    convert(A);
    convert(B);
    return 0;
}
//recursion
void solve(string s, int i, int j, int level, string temp,vector<string>& res){
    if (i == (j + 1) && level == 5) res.push_back(temp.substr(1));// Digits of a number ranging 0-255 can lie only between 0-3
    for (int k = i; k < i + 3 && k <= j; k++) {
        string ad = s.substr(i, k - i + 1); // Return if string starting with '0' or it is greater than 255.
        if ((s[i] == '0'&&ad.size()>1) || stol(ad) > 255) return; // Recursively call for another level.
        solve(s, k + 1, j, level + 1, temp + '.' + ad, res);
    }
}
solve(s, 0, n - 1, 1, "", ans);
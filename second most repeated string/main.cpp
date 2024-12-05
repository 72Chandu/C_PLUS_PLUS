//using hashmap
// string secFrequent(string a[], int n) {
//   map<string, int> freq;
//     for (int i = 0; i < n; ++i) {
//         freq[a[i]]++;
//     }
//     priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
//     for(auto i: freq){
//         pq.push(make_pair(i.second, i.first));
//         if(pq.size()>2) pq.pop();
//     }
//     if(pq.size()>1) return pq.top().second;
//     else return "";
// }
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
string secondMostFrequent(string a[], int n) {
    map<string, int> freq;
    for (int i = 0; i < n; ++i) {// Count frequencies of each string in the array
        freq[a[i]]++;
    }
    vector<pair<int, string>> freqVec;// Create a vector of pairs to store frequencies
    for (auto& entry : freq) {
        freqVec.push_back({entry.second, entry.first});
    }
    sort(freqVec.begin(), freqVec.end(), greater<pair<int, string>>());// Sort the frequencies in descending order
    if (freqVec.size() > 1) {// Find the second most frequent string
        return freqVec[1].second;
    } else {
        return ""; // Return empty string if there's no second most frequent string
    }
}
int main() {
    string arr[] = {"apple", "banana", "apple", "orange", "banana", "apple", "apple"};
    int n = sizeof(arr) / sizeof(arr[0]);
    string secondMostFreq = secondMostFrequent(arr, n);
    cout << "Second most frequent string: " << secondMostFreq << endl;
    return 0;
}

// s=aabababa; ans=b;
/*a simple solution is to start from the first charter , count its occurance then  second charcter and so on ehile counting these
occurance keep track of max and second max->0(n^2) , o(n)-> using hash map*/
/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void countOccurrences(const string& str) {
    vector<int> counts(256, 0); // Assuming ASCII characters

    // Count occurrences of each character
    for (char c : str)
        counts[c]++;

    // Find the max and second max occurrences
    int maxCount = 0, secondMaxCount = 0;
    char maxChar, secondMaxChar;
    for (int i = 0; i < 256; ++i) {
        if (counts[i] > maxCount) {
            secondMaxCount = maxCount;
            secondMaxChar = maxChar;
            maxCount = counts[i];
            maxChar = static_cast<char>(i);
        } else if (counts[i] > secondMaxCount) {
            secondMaxCount = counts[i];
            secondMaxChar = static_cast<char>(i);
        }
    }

    // Output the results
    cout << "Most frequent character: " << maxChar << " with frequency " << maxCount << endl;
    cout << "Second most frequent character: " << secondMaxChar << " with frequency " << secondMaxCount << endl;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    countOccurrences(str);
    return 0;
}*/
// using hash map-> o(n)

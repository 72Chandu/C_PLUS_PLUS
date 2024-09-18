#include <iostream>
#include <vector>
using namespace std;
vector<int> prefixSum(vector<int> &v, int n) {// Function to calculate the prefix sum
    for (int i = 1; i <= n; i++) {
        v[i] = v[i] + v[i - 1];
    }
    return v; // Return the modified vector
}
int main() {
    vector<int> v = {5, 1, 2, 3, 4};
    int q, r, l;
    cout << "Enter the number of queries: ";
    cin >> q;
    while (q--) {
        cout << "Enter index r: ";
        cin >> r;
        cout << "Enter index l: ";
        cin >> l;
        int ans = 0;
        vector<int> prefixSums = prefixSum(v, r);// Calculate prefix sums[5,6,8,11,15]
        //Subtract prefix sum of 'l-1' from prefix sum of 'r'
        ans=prefixSums[r]-prefixSums[l - 1] ;
        cout<<"Sum from index "<<l<<" to "<<r<<": "<< ans << endl;
    }
    return 0;
}
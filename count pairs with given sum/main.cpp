/*https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
Example 1: Input:  N = 4, K = 6  arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.

Example 2: Input:N = 4, K = 2   arr[] = {1, 1, 1, 1}
Output: 6
Explanation: 
Each 1 will produce sum 2 with any 1.
*/
/*int countNofPairs=0;// brute force approch
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(a[i]+a[j]==k) countNofPairs++;
    }
}*/
#include <unordered_map> // Required for unordered_map
using namespace std; // Required for accessing standard library elements

class Solution {
public:
    int getPairsCount(int arr[], int n, int k) {
        int count = 0; // Initialize count to 0
        
        unordered_map<int, int> m; //hash table to store the frequency of elements encountered
        for (int i = 0; i < n; i++) {//populate the hash table with element frequencies
            m[arr[i]]++;
        }
        for (int i = 0; i < n; i++) {//count pairs with sum equal to k
            count += m[k - arr[i]]; // Add the frequency of complement to the count
            // If the element itself is the complement, decrement count to avoid counting it twice
            if (k - arr[i] == arr[i]) 
                count--;
        }
        return count / 2; // Return the count divided by 2 (each pair is counted twice)
    }
};
/*
arr[] = {1, 5, 7, 3, 7, 8, 2}  k = 10.
creates an empty hash table m.
populate the hash table m with the frequency of each element:

For arr[0] = 1, m[1] is updated to 1.
For arr[1] = 5, m[5] is updated to 1.
For arr[2] = 7, m[7] is updated to 1.
For arr[3] = 3, m[3] is updated to 1.
For arr[4] = 7, m[7] is updated to 2.
For arr[5] = 8, m[8] is updated to 1.
For arr[6] = 2, m[2] is updated to 1.
hash table m : {1: 1, 5: 1, 7: 2, 3: 1, 8: 1, 2: 1}.
count pairs with sum equal to k:

arr[0] = 1,--> k - arr[0] = 10 - 1 = 9 in m. There are no elements with value 9,  count= 0.
arr[1] = 5,--> k - arr[1] = 10 - 5 = 5 in m. There's one element with value 5,  count= 1.
arr[2] = 7,--> k - arr[2] = 10 - 7 = 3 in m. There's one element with value 3,  count= 2.
arr[3] = 3,--> k - arr[3] = 10 - 3 = 7 in m. There are two elements with value 7,  count= 4. Additionally, since arr[3]=3 and there's another 3 in the array, we decrement count by 1 to avoid double-counting the pair (3, 7) with itself.
arr[4] = 7,--> k - arr[4] = 10 - 7 = 3 in m. There's one element with value 3,  count= 5.
arr[5] = 8,--> k - arr[5] = 10 - 8 = 2 in m. There's one element with value 2,  count= 6.
arr[6] = 2,--> k - arr[6] = 10 - 2 = 8 in m. There's one element with value 8,  count= 7.
Finally, the code returns count / 2, which is 7 / 2 = 3.5, but since it's an integer division, the result is 3.

So, there are 3 pairs in the array arr[] whose sum equals 10: (1, 9), (5, 5), and (2, 8).*/
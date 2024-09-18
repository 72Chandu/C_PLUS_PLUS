/*Input: a1[] = {11, 7, 1, 13, 21, 3, 7, 3} a2[] = {11, 3, 7, 1, 7} Output:Yes
Explanation:a2[] is a subset of a1[]
Example 2:Input: a1[] = {1, 2, 3, 4, 4, 5, 6} a2[] = {1, 2, 4} Output:Yes
Explanation: a2[] is a subset of a1[]
Example 3: Input: a1[] = {10, 5, 2, 23, 19} a2[] = {19, 5, 3} Output: No
Explanation: a2[] is not a subset of a1[]

count=0;
for(int i=0;i<n1;i++){
    for(int j=0;j<n2;j++){
        if(a2[j]==a1[i]) count++;
    }
}
if(n2==count) return true;
*/
#include <unordered_map>
#include <string>

std::string isSubset(int a1[], int a2[], int n, int m) {
    std::unordered_map<int, int> mp;
    
    // Store elements of a1[] and their counts in the unordered_map
    for (int i = 0; i < n; i++) {
        mp[a1[i]]++;
    }
    
    // Check if each element of a2[] exists in a1[] with sufficient count
    for (int i = 0; i < m; i++) {
        // If the element does not exist in a1[] or its count in a1[] is already 0,
        // then a2[] is not a subset of a1[]
        if (mp.find(a2[i]) == mp.end() || mp[a2[i]] == 0) {
            return "No";
        }
        // Decrement the count of the element in a1[] as it is found in a2[]
        mp[a2[i]]--;
    }
    
    // If all elements of a2[] are found in a1[] with sufficient count, a2[] is a subset of a1[]
    return "Yes";
}

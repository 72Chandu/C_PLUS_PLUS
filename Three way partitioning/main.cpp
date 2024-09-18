/*divided into three parts: elements <a |elements b/w a&b|elements>b
output is 1 if you modify the given array successfully.

Input:  n = 5 A[] = {1, 2, 3, 3, 4} [a, b] = [1, 2]
Output: 1
Explanation: One possible arrangement is:{1, 2, 3, 3, 4}. If you return a valid arrangement, output will be 1.

Input: n = 6  A[] = {1, 4, 3, 6, 2, 1} [a, b] = [1, 3]
Output: 1
Explanation: One possible arrangement is: {1, 3, 2, 1, 4, 6}. If you return a valid arrangement, output will be 1.

void threeWayPartition(vector<int>& arr, int low, int high) {
    vector<int> v;
    int n = arr.size();
    for (int i = 0; i < n; i++) { // Move elements smaller than 'low' to the beginning
        if (arr[i] < low) v.push_back(arr[i]);
    }
    for (int i = 0; i < n; i++) { // Move elements in the range [low, high] next
        if (arr[i] >= low && arr[i] <= high) v.push_back(arr[i]);
    }
    for (int i = 0; i < n; i++) { // Move elements greater than 'high' to the end
        if (arr[i] > high)  v.push_back(arr[i]);
    }
    for (int i = 0; i < v.size(); i++) {  // Print the modified array
        cout << v[i] << " ";
    }
}
*/
 void threeWayPartition(vector<int>& arr, int a, int b){
    int l = 0;// Initialize left pointer for elements less than 'a'
    int r = arr.size() - 1;// Initialize right pointer for elements greater than 'b'
    for (int i = 0; i <= r;) {
        // If current element is less than 'a', swap it with element at 'l' and move 'l' and 'i'
        if (arr[i] < a) {
            swap(arr[l], arr[i]);
            l++;
            i++;
        }
        // If current element is greater than 'b', swap it with element at 'r' and decrement 'r'
        else if (arr[i] > b) {
            swap(arr[r], arr[i]);
            r--;
        }
        // If current element is within the range [a, b], move to the next element
        else {
            i++;
        }
    }
}

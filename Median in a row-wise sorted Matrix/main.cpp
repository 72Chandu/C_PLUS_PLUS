/*R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives 
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 
Example 2:Input: R = 3, C = 1
M = [[1], [2], [3]]
Output: 2
Explanation: Sorting matrix elements gives 
us {1,2,3}. Hence, 2 is median.

approch-1
store the elements of the given matrix in aray of size->o(r*c)
sort the array -> o(r*c*log(r*c))
median =arr[(r*c)/2]
t=o(r*clog(r*c))   s=o(r*c);

approch-2;
binary search
for a number to be a median there should be exactly n/2 number which are less than this number


list=[]
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        list.add(a[i][j])
    }
}
sort(list);
return list[(m*n)/2];
*/
int median(vector<vector<int>> &a, int r, int c){
     int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < r; i++) {
        if (a[i][0] < min) min = a[i][0]; // minimum elements
        if (a[i][c - 1] > max) max = a[i][c - 1]; // maximum elements
    }
    int desired = (r * c + 1) / 2;
    while (min < max) {
        int mid = min + (max - min) / 2;
        int place = 0;
        for (int i = 0; i < r; i++) { // count the smaller elements than mid
            place +=upper_bound(a[i].begin(), a[i].end(), mid) - a[i].begin();////upper_bound(start_itr, end_itr, value)-> return iterator to first greater elements for sorted array/vector
        }
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;        
    }
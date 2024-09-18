/*Input: N = 5 arr[] = 90 100 78 89 67
Output: 89 Explanation: After sorting the array  middle element is the median 

Example 2: Input: N = 4 arr[] = 56 67 30 79 Output: 61
Explanation: In case of even number of  elements, average of two middle elements is the median.
*/
int find_median(vector<int> v){
		    int n = v.size();
            sort(v.begin(), v.end());
             if (n % 2 != 0) return static_cast<int>(v[n / 2]);
            else  return static_cast<int>((v[(n - 1) / 2] + v[n / 2]) / 2.0);
		}
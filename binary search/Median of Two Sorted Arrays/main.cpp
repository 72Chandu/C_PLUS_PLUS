/*
arr1= 1 2 3 7 10 12 arr2=2 3 6 15 sorted= 1 2 3 3 4 |6 7 10 12 15(5 ele in left ,5 ele in righ)
4 is greatest of left , 6 is smallest of the right

taking 2 ele from arr1 and 3 ele from arr2 for left side rest on right side
arr1   1 3(l1)|(r1)4 7 10 12  l2>r1->l=mid+1
arr2 2 3 6(l2)|(r2)15
=> 1 2 3 3 6|4 7 10 12 15 -> not sorted

arr1 1 3 4(l1)|(r1)7 10 12 l1<r2, l2<r1 -> midian=max(l1,l2)+min(l1,l2)/2
arr2   2 3(l2)|(r2)6 15
=> 1 2 3 3 4 |6 7 10 12 15 -> sorted possible onley when we take 3 ele from arr1

arr1   1 3 4 7(l1)|(r1)10 12  l1>r2 -> h=mid-1
arr2         2(l2)|(r2)3 6 15
=> 1 2 3 4 7|3 6 10 12 15 ->not sorted
ex:-2 a1=7 12 14 15  a2=1 2 3 4 9 11 -> appaly bs on smaller array (4 element)

0    4 -> mid1=2(peak 2 element from a1) mid2=5-2=3(3 ele from a2)
l    h
 7 12(l1)|(r1)24 15
1 2 3(l2)|(r2)4 9 11  l1>r2 ->h=mid-1

0    1 -> mid1=0 mid2=5 
l    h
        -(l1)|(r1)7 12 14 15
1 2 3 4 9(l2)|(r2)11  l2>r1-> l=mid+1
->
1   mid1=1 mid2=4 
l,h
      7(l1)|(r1)12 14 15  l1<r2, l2<r1 -> midian=max(l1,l2)+min(l1,l2)/2
1 2 3 4(l2)|(r2)9 11
l1=a1[mid-1] l2=a2[mid2-1] r1=a1[mid1] r2=a2[mid2]


for odd 
*/
Approach 1:
Time Complexity: O((n + m) * log(n + m)).
Space Complexity: O(n + m), where ‘n’ and ‘m’ are the sizes of the arrays.
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();// Get the sizes of both input arrays.
        int m = nums2.size();
        vector<int> merged; // Merge the arrays into a single sorted array.
        for (int i = 0; i < n; i++) {
            merged.push_back(nums1[i]);
        }
        for (int i = 0; i < m; i++) {
            merged.push_back(nums2[i]);
        }
        sort(merged.begin(), merged.end()); // Sort the merged array.
        int total = merged.size();// total number of elements in the merged array.
        if (total % 2 == 1) {  //  return the middle element as the median.
            return static_cast<double>(merged[total / 2]);
        } else { //calculate the average of the two middle elements as the median
            int middle1 = merged[total / 2 - 1];
            int middle2 = merged[total / 2];
            return (static_cast<double>(middle1) + static_cast<double>(middle2)) / 2.0;
        }
    }
};
Approach 2: Two-Pointer Method
Initialize two pointers, i and j, both initially set to 0.
Move the pointer that corresponds to the smaller value forward at each step.
Continue moving the pointers until you have processed half of the total number of elements.
Calculate and return the median based on the values pointed to by i and j.
Time Complexity: O(n + m), 
Space Complexity: O(1).

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0, m1 = 0, m2 = 0;
        for (int count = 0; count <= (n + m) / 2; count++) {  // Find median.
            m2 = m1;
            if (i != n && j != m) {
                if (nums1[i] > nums2[j]) {
                    m1 = nums2[j++];
                } else {
                    m1 = nums1[i++];
                }
            } else if (i < n) {
                m1 = nums1[i++];
            } else {
                m1 = nums2[j++];
            }
        }
        if ((n + m) % 2 == 1) { // Check if the sum of n and m is odd.
            return static_cast<double>(m1);
        } else {
            double ans = static_cast<double>(m1) + static_cast<double>(m2);
            return ans / 2.0;
        }
    }
};
Approach 3: Binary Search
Use binary search to partition the smaller of the two input arrays into two parts.
Find the partition of the larger array such that the sum of elements on the left side of the partition in both arrays is half of the total elements.
Check if this partition is valid by verifying if the largest number on the left side is smaller than the smallest number on the right side.
If the partition is valid, calculate and return the median.
Time Complexity: O(logm/logn)
Space Complexity: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        // Ensure nums1 is the smaller array for simplicity
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2; // Calculate the left partition size
        int low = 0, high = n1;
        while (low <= high) {
            int mid1 = (low + high) >> 1; // Calculate mid index for nums1
            int mid2 = left - mid1; // Calculate mid index for nums2
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            // Determine values of l1, l2, r1, and r2
            if (mid1 < n1) r1 = nums1[mid1];
            if (mid2 < n2) r2 = nums2[mid2];
            if (mid1 - 1 >= 0)  l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)  l2 = nums2[mid2 - 1];
            if (l1 <= r2 && l2 <= r1) {
                // The partition is correct, we found the median
                if (n % 2 == 1)  return max(l1, l2);
                else  return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if (l1 > r2) {
                high = mid1 - 1; // Move towards the left side of nums1
            }
            else {
                low = mid1 + 1;// Move towards the right side of nums1
            }
        }
        return 0; // If the code reaches here, the input arrays were not sorted.
    }
};
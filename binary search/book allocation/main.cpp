// used to minimize or maximize something
/* https://www.interviewbit.com/problems/allocate-books/
A book will be allocated to exactly one student.
Each student has to be allocated at least one book.
Allotment should be in contiguous order
Example Input
Input 1:
A = [12, 34, 67, 90] -> N books The ith book has A[i] number of pages
B = 2  ->no of students book is allocated
Output 1: 133 ->maximum number of pages allocated to a student is minimum.
There are two students. Books can be distributed in following fashion : 
1)  [12] and [34, 67, 90]
    Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
2)  [12, 34] and [67, 90]
    Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
3)  [12, 34, 67] and [90]
    Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages
    Of the 3 cases, Option 3 has the minimum pages = 113.*/
#include <bits/stdc++.h>
using namespace std;
bool isbooks_allocated(int* book, int n, int mid, int s) {
    int count = 1;
    int page_sum = 0;
    for (int i = 0; i < n; i++) {
        if (book[i] > mid) return false;
        if (book[i] + page_sum <= mid) {
            page_sum += book[i];
        } else {
            count++;
            page_sum = book[i];
        }
    }
    return count <= s;
}
int main() {
    int a[]={12, 34, 67, 90};
    int n=sizeof(a)/sizeof(int);
    int student = 2;
    int low = 0;
    int high =accumulate(a, a+n, 0);// accumulate(intial, final, intial sum)->for sumation 
    int ans= -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isbooks_allocated(a, n, mid, student)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
/*A = [12, 34, 67, 90]
12+34+67+90=203
search space 
 0-----------203 , mid=101 is 101 number of page is able to distribute among 2 student
 s1->12+34=46
 s2->67
 extra 90 page is remaining so not possible , lo=mid+1
 
 102-----------203 , mid=152 
 s1->12+34+64=110
 s2->90 
 this is possible ans=152, we have to find minimum so, hi=mid-1
 
 102-----------151 , mid=126
 s1->12+34+64=110
 s2->90 
 this is possible ans=126, we have to find minimum so, hi=mid-1
 
 102-----------125 , mid=113
 s1->12+34+64=110
 s2->90 
 this is possible ans=113, we have to find minimum so, hi=mid-1
 
 102-----------112 , mid=107
 s1->12+34=46
 s2->64
 extra 90 page is remaining so not possible , lo=mid+1
 
 108-----------112 , mid=110
 s1->12+34=46
 s2->64
 extra 90 page is remaining so not possible , lo=mid+1
 
 111-----------112 , mid=111
 s1->12+34=46
 s2->64
 extra 90 page is remaining so not possible , lo=mid+1
 
 112-----------112 , mid=112
 s1->12+34=46
 s2->64
 extra 90 page is remaining so not possible , lo=mid+1
 
 */

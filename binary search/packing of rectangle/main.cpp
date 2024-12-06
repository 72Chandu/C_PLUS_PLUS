/*
n-> no of rectngle, having same (width->w, heigth->h) size of square need to fit the all rectangle=max(n*w,n*h)
ex:-> n=10 h=3 w=2 
+---+---+---+---+    -> 3 row  4 column
| 1 | 2 | 3 | 4 |
+---+---+---+---+
| 5 | 6 | 7 | 8 |
+---+---+---+---+
| 9 | 10        |
+---+---+---+---+   4x3 rectange -> 12> 10 means it accomadate

0 ->is minimum length of square where we can not accomadate all rectangles
'r' ->is maximum length of square where 'n' rectangles can accomadate 

0-----------------r  ->  thare is one point after that all become true 
f f f....t t t t t   -> t=true-> can accomadate n rectangles, f=false->can not accomadate
if we encounter the "t" serchin left side , if we encounter 'f' then serch in right
0 1 2 3 ...8 9 10.....1e^18
f f f f    f t t t .....
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
bool isAccomadeTheRec(ll w, ll h, ll n, ll x){
    ll cnt = 0;
    ll nm1 = (x / w);  // no. of rectangles that can be horizontally aligned in the square
    ll nm2 = (x / h); // no. of rectangles that can be vertically aligned in the square
    cnt = nm1 * nm2; // total no. of rectangles in the square of side x
    return cnt >= n;
}
int main(){
    ll w, h, n;
    cin >> w >> h >> n;
    ll lo = 0, r = 1, mid;
    // loop to find some big value of r which can contain all n rectangles
    while (isAccomadeTheRec(w, h, n, r) == false)
        r *= 2;
    // we can also initialize i as n/2, since we have found a square of side n,
    // which can contain n rectangles in it, but a square of side n/2 can not
    while (lo + 1 < r){  // loop to find the answer, i.e. the transition point
        mid = lo + (r - lo) / 2;
        if (isAccomadeTheRec(w, h, n, mid))
            r = mid-1;//searching in left
        else
            lo = mid+1;//searching in right
    }
    cout << r;
    return 0;
}

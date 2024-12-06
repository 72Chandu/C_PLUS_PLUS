//https://www.spoj.com/problems/PRATA/
/*
paratha=10 , cook=4  rank of cook =1  2  3  4
                                   c1 c2 c3 c4
let c4 cook karega then total time = 1*4+2*4+3*4+4*4+5*4+6*4+7*4....10*4 = 4*[n*(n+1)/2] = 220

0------------220(time taken by cook highest rank when all paratha make by him onley)
mid=110
c1= 1+2*1+3*1+...10*1=55 yes banjayega  55<=110 , 110minutes me banjayega to more then 110 me obious banjayega so hi=mid-1

0--------109 mid=54 
c1=1*1+1*2+1*3+1*4+..1*10= 55minutes >54
c1=1*1+1*2+1*3+1*4+..1*9=45
c2=1*2=2 
yes we can able to make ans=54 , hi=mid-1

0-----------53   mid=26 minutes
c1=1*2+2*1+3*1...7*1=29
c1=1*2+2*1+3*1...6*1=21->6paratha
c2=2*1+2*2+2*3+2*4=20 ->4 paratha
yes we are able to make it ans=26, hi=mid-1

0-----------25 mid=12 minutes 
c1=1*1+2*2 3*1+4*1=10 -> 4
c2=1*2+2*2+3*2=12 -> 3
c3=1*3+2*3=9 ->2
c4=1*4=4 ->1    yes we are able to make it ans=12, hi=mid-1

0-----------11 mid=5
c1=1*1+2*2 3*1+4*1=10 -> 4
c2=1*2+2*2=6 -> 2
c3=1*3=3->1
c4=1*4=4 ->1    not, possible lo=mid+1

6--------11  mid=8
c1=1*1+2*2+3*1 =6 -> 3
c2=1*2+2*2=6 -> 2
c3=1*3=3->1
c4=1*4=4 ->1  not possible lo=mid+1

9-----11  mid=10
c1=1*1+2*2 3*1+4*1=10 -> 4
c2=1*2+2*2=6 -> 2
c3=1*3+2*3=9 ->2
c4=1*4=4 ->1    not possible lo=mid+1

11---11 mid=11
c1=1*1+2*2 3*1+4*1=10 -> 4
c2=1*2+2*2=6 -> 2
c3=1*3+2*3=9 ->2
c4=1*4=4 ->1  not possible lo=mid+1

lo=12 hi=11 stop 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossibleSol(const vector<int>& cooksRank, int Np, int mid) {
    int currP = 0; // current count of parathas cooked
    for (int i = 0; i < cooksRank.size(); ++i) {
        int r = cooksRank[i];
        int j = 1;
        int timeTaken = 0;
        while (true) {
            if (timeTaken + j * r <= mid) {
                ++currP;
                timeTaken += j * r;
                ++j;
            } else {
                break;
            }
        }
        if (currP >= Np) {
            return true;
        }
    }
    return false;
}

int minTimeToCompleteOrder(const vector<int>& cooksRank, int Np) {
    int lo = 0;
    int highestRank = *max_element(cooksRank.begin(), cooksRank.end());
    int hi = highestRank * (Np * (Np + 1) / 2);
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (isPossibleSol(cooksRank, Np, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int Np, Nc;
        cin >> Np >> Nc;
        vector<int> cooksRank(Nc);
        for (int i = 0; i < Nc; ++i) {
            cin >> cooksRank[i];
        }
        cout << minTimeToCompleteOrder(cooksRank, Np) << endl;
    }
    return 0;
}

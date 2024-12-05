/*I 1
V 5
X 10
L 50
C 100
D 500
M 1000*/
#include <unordered_map>
#include <string>
using namespace std;
int romanToDecimal(string s) {
    unordered_map<char, int> romanValues = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int result = 0;
    int prevValue = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        int value = romanValues[s[i]];
        if (value < prevValue) {
            result -= value;
        } else {
            result += value;
        }
        prevValue = value;
    }
    return result;
}
/*xiv  -> (5<0->r=5 p=5), (1<5 r=4 p=1), (10<1 r=14 p=10) */

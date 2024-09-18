#include <bits/stdc++.h> 
bool isArmstrong(int num) {
    int count = 0;
    int num_ = num;  
    while (num) {
        num = num / 10;
        count++;
    }
    num =num_;  
    int res = 0;
        while (num) {
        int x = num % 10;
        res += pow(x, count);
        num = num / 10;
    }
    if (res ==num_) return true;
    else return false;
}
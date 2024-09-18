// add 2  number represented by 2 array -> geegs
       1    <-carry
a  9 5 4 9  <-i i decrese kartey jayega
in 0 1 2 3  <-j j decrese kartey jayega
b    2 1 4
in   0 1 2
----------------
    9 7 6 3 
int carry=0
int x a[i]+b[j]+carry // 9+4=13
int digit=x%10 //3->push in output array
carry=x/10//1
 string calc_Sum(int *a,int n,int *b,int m){
    // Complete the function
       int carry=0;
    string ans;
    int i=n-1;
    int j=m-1;
    while(i>=0 && j>=0){
        int x= a[i]+b[j]+carry;
        int digit=x%10;
        ans.push_back(digit+'0');
        carry=x/10;
        i--;
        j--;
    }
    while(i>=0){
        int x =a[i]+0+carry;
        int digit=x%10;
        ans.push_back(digit+'0'); 
        carry=x/10;
        i--;
    }
    while(j>=0){
        int x= 0+b[j]+carry;
        int digit=x%10;
        ans.push_back(digit+'0');
        carry=x/10;
        j--;
    }
    if(carry){
        ans.push_back(carry+'0');
    }// 3 6 7 9 
    while(ans[ans.size()-1]=='0'){
        ans.pop_back();//removing last 0
    }
    reverse(ans.begin(), ans.end());//9 7 6 3
    return ans;
    }
/*Example 1: Input: N = 5  Output: 120
Explanation : 5! = 1*2*3*4*5 = 120
Example 2: Input: N = 10 Output: 3628800
Explanation : 10! = 1*2*3*4*5*6*7*8*9*10 = 3628800
    2 -> carry
    2 4
    x 5
    ----
    120   (5*4+0)=0, carry=2  (5*2+2)=2 carry 1,  (5*gar+1)=1  -> 120
    int prod=result[j]*i+carry
*/
vector<int> factorial(int N){
         if (N == 0) return {1};
         vector<int> result = {1}; // Initialize result to 1
         for (int i = 2; i <= N; ++i) {// Calculate factorial
          int carry = 0;
          for (int j = 0; j < result.size(); ++j) {
            int prod = result[j] * i + carry;
            result[j] = prod % 10; // Store the units place digit
            carry = prod / 10; // Update carry for next iteration
        }
        while (carry) {// Propagate remaining carry to higher digits
            result.push_back(carry % 10);
            carry /= 10;
        }
    }
    // Reverse the result to get the digits in correct order
    reverse(result.begin(), result.end());
    return result;
    }

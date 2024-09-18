/*Input: 5     111 222 333 444 555     Output: 1
Explanation:
A[0] = 111 //which is a palindrome number.
A[1] = 222 //which is a palindrome number.
A[2] = 333 //which is a palindrome number.
A[3] = 444 //which is a palindrome number.
A[4] = 555 //which is a palindrome number.
As all numbers are palindrome so This will return 1.
Example 2:Input: 3    121 131 20   Output:0
Explanation:
20 is not a palindrome hence the output is 0.*/
bool palindrom(int num){
    string str=to_string(num);//convert integer to string
    int start=0;
    int end=str.length()-1;
    while(start<end){
        if(str[start]!=str[end]) return false;
        start++;
        end--;
    }
    return true;
}
    int PalinArray(int a[], int n){
        for(int i=0;i<n;i++){
            if(!palindrom(a[i])) return 0;
        }
        return 1;
    }
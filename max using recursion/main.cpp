                                0       INT_MIN
void findmax(int arr[], int n, int i, int &maxi){
    if(i>=n) return ;
    if(arr[i]>maxi){
        maxi=arr[i];
    }
    findmax(arr,n,i+1,maxi);
}

//
                                0       INT_MAX
void findmin(int arr[], int n, int i, int &mini){
    if(i>=n) return ;
    mini=min(arr[i],min);
    findmin(arr,n,i+1,mini);
}

//find tar in string
bool checkkey(string s, int i, int n, int tar){
    if(i>=n) return fasle;
    if(s[i]==tar) return true;
    bool ans=checkkey(s,i+1,tar);
    return ans;
}
//
void printdigits(int n){
    if(n==0) return;
    int digits=n%10;
    cout<<digits<<" ";
    printdigits(n/10);
}
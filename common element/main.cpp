/*Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.
brute force
for(int i=0;i<n1;i++){
    for(int j=0;j<n2;j++){
        for(int k=0;k<n3;k++){
            if(a[i]==b[j]==c[k]) cout<a[i];
        }
    }
}
optimal
First, you can iterate through the elements of the first array and store each element in a hash set.
Then, iterate through the elements of the second array and check if each element exists in the hash set. If it does, mark it as a common element.
Finally, iterate through the elements of the third array and check if each element is marked as common. If it is, then it is a common element among all three arrays.

vector<int> findCommonElements(int a[], int b[], int c[], int n1, int n2, int n3) {
    unordered_set<int> s;
    unordered_set<int> common;
    vector<int> result;
    // Iterate over the elements of the first array and store them in a hash set
    for (int i = 0; i < n1; i++) {
        s.insert(a[i]);
    }

    // Iterate over the elements of the second array and check if each element exists in the hash set
    // If it does, mark it as a common element
    for (int i = 0; i < n2; i++) {
        if (s.find(b[i]) != s.end()) {
            common.insert(b[i]);
        }
    }

    // Iterate over the elements of the third array and check if each element is marked as common
    // If it is, then it is a common element among all three arrays
    for (int i = 0; i < n3; i++) {
        if (common.find(c[i]) != common.end()) {
            result.push_back(c[i]);
        }
    }

    return result;
}*/
//handel all cases
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
    int i = 0, j = 0, k = 0;
    vector<int> v; //common elements
    set<int> s;//store unique common elements
    while (i < n1 && j < n2 && k < n3) {
        if (A[i] == B[j] && B[j] == C[k]) {
            s.insert(A[i]);//Insert the common element into the set to ensure uniqueness
            i++;
            j++;
            k++;
        } 
        // If A[i] is smaller than or equal to B[j] and C[k], move pointer i
        else if (A[i] <= B[j] && A[i] <= C[k])  i++;
        
        // If B[j] is smaller than or equal to A[i] and C[k], move pointer j
        else if (B[j] <= A[i] && B[j] <= C[k])  j++;
        
        // If C[k] is smaller than or equal to B[j] and A[i], move pointer k
        else if (C[k] <= B[j] && C[k] <= A[i])  k++;
    }
    v.assign(s.begin(), s.end()); // Assign the unique common elements from set to vector v
    return v;
}

// comman element in 3 sorted array  -> geegs 
1 5 10 20 40 80
i
6 7 20 80 100
j
3 4 15 20 30 70 80 12
k
vector<int>commanelement(int a[], int b[], int c[], int n1, int n2, int n3){
    vector<int>ans;
    set<int>s;//store distinct no
    int i=0, j=0 , k=0;
    while(i<n1 && j<n2 && k<n3){
        if(a[i]==b[j]==c[k]){
            //ans.push_back(a[i]);
            s.insert(a[i]);
            i++;
            j++;
            k++;
        }else if(a[i]<b[j]){
            i++;
        }else if(b[j]<c[k]){
            j++;
        }else{
            k++;
        }
    }
    for(auto i: s){
        ans.push_back(i);
    }
    return ans;
}// t.c=(n1+n2+n3)




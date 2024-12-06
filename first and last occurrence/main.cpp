//https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
vector<int> find(int arr[], int n , int x ){
        vector<int> v(2, -1);
       for(int i=0;i<n;i++){//finding first
           if(arr[i]==x){
               v[0]=i;
               break;
           }
       }
        for(int i=n;i>=0;i--){//finding last
           if(arr[i]==x){
               v[1]=i;
               break;
           }
       }
        return v;
    }
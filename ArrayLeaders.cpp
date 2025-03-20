//https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?page=1&sortBy=submissions
vector<int> leaders(vector<int>& arr) {            // last test case is fail
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            bool isleader=true;
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]>arr[i]){
                    isleader=false;
                    break;
                }
            }
            if(isleader) ans.push_back(arr[i]);
        }
        return ans;
    }
// m-2
vector<int> leaders(vector<int>& arr) {
        vector<int>ans;
        int n=arr.size();
        int maxright=arr[n-1];
        ans.push_back(maxright);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=maxright){
                maxright=arr[i];
                ans.push_back(arr[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

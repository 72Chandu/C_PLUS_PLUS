//https://www.geeksforgeeks.org/problems/count-digit-groupings-of-a-number1520/1

int solve(int i,int prev_grp_sum,string &s){
	    if(i>=s.length()) return 1;
	    int currsum=0;
	    int result=0;
	    for(int j=i;j<s.length();j++){
	        currsum+=(s[j]-'0');//sum b/w i to j
	        if(prev_grp_sum<=currsum){
	            result+=solve(j+1,currsum,s);
	        }
	    }
	    return result;
	}//tc=o(n^3) sc=o(n)
	int TotalCount(string str){
	    return solve(0,0,str);
	}
/*  
str="1119"
{"1","11","9"}-> 1<=2<=9 valid group
             i
            (1119)
             j
                    (1119)
                       |
    "1"(119)    "11"(19)    "111"(9)   "1119"
-----
                         "1"(119)
                              |
                   1"(19)             "11"(9) "119"
                       |                   |
               "1","9"   "1","19"          "9"
 ------
                   "11"(19)
                         |
                    "1"(x) "19"   
                    
 ----
                     "111"(9)
                          |
                          "9"
"1"(119)-> {1,1,9},{1,1,19},{1,11,9},{1,119}   
"11"(19)-> "11","1","9"(not valid).. "11","19"(valid) {11,19}
"111"(9)->{111,9}
"1119"->{1119}
*/
//m-2  dp

int dp[101][1001];
	int solve(int i,int prev_grp_sum,string &s){
	    if(i>=s.length()) return 1;
	    if(dp[i][prev_grp_sum]!=-1) return dp[i][prev_grp_sum];
	    int currsum=0;
	    int result=0;
	    for(int j=i;j<s.length();j++){
	        currsum+=(s[j]-'0');//sum b/w i to j
	        if(prev_grp_sum<=currsum){
	            result+=solve(j+1,currsum,s);
	        }
	    }
	    return dp[i][prev_grp_sum]=result;
	}//tc=o(n^3) sc=o(n)
	int TotalCount(string str){
	    memset(dp,-1,sizeof(dp));
	    return solve(0,0,str);
	}

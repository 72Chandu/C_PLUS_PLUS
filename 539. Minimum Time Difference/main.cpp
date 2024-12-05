//https://leetcode.com/problems/minimum-time-difference/description/
/*
Input: timePoints = ["23:59","00:00"]
Output: 1

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 12:10->13:10 diff=1hr=60 min
*/
    int findMinDifference(vector<string>& timePoints) {
    vector<int>minutes;
    for(int i=0;i<timePoints.size();i++){
        string curr=timePoints[i];
        
        int hours=stoi(curr.substr(0,2));//stoi is used to convert string to integer
        int min=stoi(curr.substr(3,2));
        
        int totalminutes=hours*60 +min;
        minutes.push_back(totalminutes);
    }
    sort(minutes.begin(), minutes.end()); // step 2=sort
    
    int mini=INT_MAX; // step 3= calculate minimum diffrence
    for(int i=0;i<minutes.size()-1;i++){
        int diff=minutes[i+1]-minutes[i];
        mini=min(mini, diff);
    }
    /*........D I H A Y A N    S E   I M P O T A N T   CLOCK ROUND CHALTA HAI */
    int lastdiff= (minutes[0]+1440) - minutes[minutes.size()-1];
    mini=min(mini , lastdiff);
    return mini;
}
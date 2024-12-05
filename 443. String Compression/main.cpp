/*
https://leetcode.com/problems/string-compression/description/ 
*/
int compress(vector<char>& ch){
    int ind=0, count=1;
    char prev=ch[0];
    for(int i=1;i<ch.size();i++){
        if(ch[i]==prev){
            count++;
        }else{
            ch[ind++]=prev; //charcter ko dale
            if(count>1){
                int start=ind;
                while(count){
                    ch[ind++]=(count%10)+'0'; //no reverse order me dala hai 
                    count/=10;
                }
                reverse(ch.begin()+start, ch.begin()+ind);//10 se bra no ko correct order me dalna hai
            }
            prev=ch[i];
            count=1;
        }
    }
    ch[ind++]=prev;
    if(count>1){
        int start=ind;
        while(count){
            ch[ind++]=(count%10)+'0';
            count/=10;
        }
        reverse(ch.begin()+start, ch.begin()+ind);
    }
    return ind;
}
s=001 --> 010->2 flip 101->1 fip
          001         001   answer is 101-> 1 flip to become alternate number-> means 010101 or 101010

s=0001010111
  0101010101  -->start with 0 then(we want 0 at even pos if there is 1 then inc cnt and 1 at odd pos if not then inc cnt)
   i      i -> 2 flip
   
  1010101010-> 8 flip when start with 1 (we want 1 at even pos and 0 at odd pos)
 
int minFlip(string s){
    int n=s.size();
    int count0=0, count1=0;
    for(int i=0;i<n;i++){
        if(i%2==0 && s[i]=='0') count0++;
        else if(i%2==1 && s[i]=='1') count0++;
        if(i%2==0 && s[i]=='1') count1++;
        else if(i%2==1 && s[i]=='0') count1++;
    }
    return min(count0, count1);
}

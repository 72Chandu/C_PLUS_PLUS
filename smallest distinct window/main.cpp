/*
aaab
i=0->a,aa,aaa,(aaab)->4
i=1->a,aa,(aab)->3
i=2->a,(ab)->2->min->ans=2
i=3->b
find all substring
check the condition
min size
1 char->n operation
n char->n*n operation  1 ≤ |S| ≤ 10^5  (10^5)^2=10^10>10^8  there for no 
         0123456789
Input : "AABBBCBBAC" -> distict charcter(a,b,c) , ans=10(size of string)
         i->head  no of distict char=1;
         j->tail
         
Input : "AABBBCBBAC"
          i->head  no of distict char=1;
         j->tail
         
Input : "AABBBCBBAC"
           i->head  no of distict char=2
         j->tail
         .........
Input : "AABBBCBBAC"
              i->head  no of distict char=3  ans=10->6(i-j+1) , j++
         j->tail
         
input : "AABBBCBBAC"
              i->head  no of distict char=3  ans=6->5(i-j+1) ,j++
          j->tail
          
input : "AABBBCBBAC"
              i->head  no of distict char=2  ans=5 
           j->tail
           
input : "AABBBCBBAC" (move i till we get 3 different charcter)
                 i->head  no of distict char=3  ans=5-> 5 is better than 7(i-j+1) , j++
           j->tail
           
input : "AABBBCBBAC" 
                 i->head  no of distict char=3  ans=5-> 5 is better than 6(i-j+1) , j++
            j->tail
            
input : "AABBBCBBAC" 
                 i->head  no of distict char=3  ans=5-> 5 is same 5(i-j+1) , j++
             j->tail
             
input : "AABBBCBBAC" 
                 i->head  no of distict char=3  ans=5-> 4(i-j+1) , j++
              j->tail
              
input : "AABBBCBBAC" 
                 i->head  no of distict char=2  ans=4
               j->tail
               
input : "AABBBCBBAC" (move i till we get 3 different charcter)
                  i->head  no of distict char=3  ans=4->4,j++
               j->tail
               
input : "AABBBCBBAC" 
                  i->head  no of distict char=3  ans=4->3,j++
                j->tail
                
input : "AABBBCBBAC" (move i till we get 3 different charcter)
                  i->head  no of distict char=2  ans=4->3,j++
                 j->tail we can npt move i further so the answer is 3
*/
int findSubString(string s){
    int n=s.size();
       unordered_map<char,int>m;
       for(int i=0;i<n;i++){
           m[s[i]]++;
       }
       int dis=m.size();
       int head=-1;
       int tail=0;
       int ans=n;
       int count=0;
       m.clear();
       while(tail<n){
           while(head+1<n && count<dis){
               m[s[++head]]++;
               if(m[s[head]]==1){
                   count++;
               }
           }
           if(count==dis){
               ans=min(ans,head-tail+1);
           }
           if(head>=tail){
               m[s[tail]]--;
               if(m[s[tail]]==0){
                   count--;
               }
               tail++;
               if(count==dis){
                   ans=min(ans,head-tail+1);
               }
           }
       }
       return ans;
    }

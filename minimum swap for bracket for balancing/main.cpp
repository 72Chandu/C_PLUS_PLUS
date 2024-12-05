/*Input  : []][][
Output : 2
Explanation :
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

Example 2:

Input : [[][]]
Output : 0 
Explanation:
String is already balanced.

[]]]][[][[  o=0 c=0 u=0 s=0 (u=c-o)
i  -> o=1 c=0 s=0

[]]]][[][[  
 i  -> o=1 c=1 u=0 s=0
 
 []]]][[][[  
   i  -> o=1 c=2 u=1 s=0

[]]]][[][[  
    i  -> o=1 c=3 u=2 s=0
    
[]]]][[][[ 
    i  -> o=1 c=4 u=3 s=0

[]]]][[][[  
  .  i  -> o=2 c=4 u=3 s=s+u=0+3 -> u=2 (i and dot get balace and unbalanced get dec)
  1> swap-> []]][][][[  swap 2->[]][][][[  swap 3->  [][]|[][[ 
                ..                 ..                  ..
              
[][]|[][[ 
     i ->o=3 c=4 u=2 s=3 -> s=3+2=5 u->1
swap [][][]]|]][ 
         
           
[][][]]|]][ 
        i ->o=3 c=5 u=2 s=5 

[][][]]|]][ 
         i ->o=3 c=5 u=2 s=5 
*/
int minimumNumberOfSwaps(string s){
        int open=0, close=0, swaps=0, unbalanced=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='['){
                open++;
                if(unbalanced>0){
                    swaps+=unbalanced;
                    unbalanced--;
                }
            } else{
                close++;
                unbalanced=close-open;
            }
        }
        return swaps;
    }
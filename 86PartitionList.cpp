/** https://leetcode.com/problems/partition-list/description/?envType=study-plan-v2&envId=top-interview-150
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small=new ListNode(0);
        ListNode* large=new ListNode(0);

        ListNode* smallP=small;
        ListNode* largeP=large;
        while(head){
            if(head->val<x){
                smallP->next=head;
                smallP=smallP->next;
            }else{
                largeP->next=head;
                largeP=largeP->next;
            }
            head=head->next;
        }
        smallP->next=large->next;
        largeP->next=NULL;
        return small->next;
    }
};
/*
Input: head = [1 -> 4 -> 3 -> 2 -> 5 -> 2], x = 3
               head-> x<3 
small->1  
      smallptr
large
largeptr

1 -> 4 -> 3 -> 2 -> 5 -> 2
     head-> x<3 
small->1  
      smallptr
large->4
    largeptr

1 -> 4 -> 3 -> 2 -> 5 -> 2
         head-> x<3 
small->1  
         smallptr
large->4 -> 3
          largeptr

1 -> 4 -> 3 -> 2 -> 5 -> 2
              head-> x<3 
small->1 ->2 
          smallptr
large->4 ->3
         largeptr

1 -> 4 -> 3 -> 2 -> 5 -> 2
                  head-> x<3 
small->1 ->2 
          smallptr
large->4 ->3 -> 5
             largeptr

1 -> 4 -> 3 -> 2 -> 5 -> 2
                       head-> x<3 
small->1 ->2 -> 2
              smallptr
large->4 ->3 -> 5
             largeptr

1 -> 4 -> 3 -> 2 -> 5 -> 2
                          head-> x<3 
small->1 ->2 -> 2
              smallptr
large->4 ->3 -> 5
             largeptr
smallptr->next=large->next
small->1 ->2 -> 2 -> 4 ->3 -> 5
largeptr->next=null
small->1 ->2 -> 2 -> 4 ->3 -> 5 ->null
return small->next
*/

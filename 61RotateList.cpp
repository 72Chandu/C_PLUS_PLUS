/**https://leetcode.com/problems/rotate-list/?envType=study-plan-v2&envId=top-interview-150
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
    ListNode* rotateRight(ListNode* head, int k) {
       if(!head || !head->next || k==0) return head;
       ListNode* curr=head;
       int len=1;
       while(curr->next){
        curr=curr->next;
        len++;
       }
       curr->next=head;//connecting last node to first
       k=k%len;
       int stepsToNewHead=len-k;
       ListNode* newtail=head;
       for(int i=1;i<stepsToNewHead;i++){
        newtail=newtail->next;
       }
       ListNode* newhead=newtail->next;
       newtail->next=nullptr;
       return newhead;
    }
};
/*
head = [1, 2, 3, 4, 5], k = 2
1 -> 2 -> 3 -> 4 -> 5 -> nullptr
1 -> 2 -> 3 -> 4 -> 5 -> 1
          |
1 -> 2 -> 3   4 -> 5 ->1
        newhead
4 -> 5 -> 1 -> 2 -> 3 -> nullptr
*/

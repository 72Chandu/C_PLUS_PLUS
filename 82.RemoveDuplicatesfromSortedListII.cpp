/** https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/?envType=study-plan-v2&envId=top-interview-150
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode newnode(0);
        newnode.next=head;
        ListNode* prev=&newnode;//point last node to be distinct
        while(head!=nullptr){
            if(head->next!=nullptr && head->val==head->next->val){
                int duplicate_val=head->val;
                while(head!=nullptr && head->val==duplicate_val){//skip all node with same value
                   head=head->next;
                }
                prev->next=head;// Remove duplicates by linking prev->next to the next non-duplicate node
            }else{
                prev=prev->next;
                head=head->next;
            }
        }
        return newnode.next;

    }
};
/*
1 → 2 → 3 → 3 → 4 → 4 → 5
dummy → 1 → 2 → 3 → 3 → 4 → 4 → 5
  ↑
 prev
         ↑
        head

head->val != head->next->val (1 ≠ 2)
dummy → 1 → 2 → 3 → 3 → 4 → 4 → 5
        ↑    ↑
      prev  head
head->val != head->next->val (2 ≠ 3)
dummy → 1 → 2 → 3 → 3 → 4 → 4 → 5
            ↑    ↑
           prev  head
head->val == head->next->val (3 == 3)
dummy → 1 → 2       3 → 3 → 4 → 4 → 5
             ↑      ↑-------↑
           prev     head (moving over duplicates)

After skipping:
head = 4

dummy → 1 → 2 → 3 → 3 → 4 → 4 → 5
            ↑           ↑
           prev         head
Set prev->next = head to remove all 3s:
dummy → 1 → 2 → 4 → 4 → 5
            ↑   ↑
           prev  head
head->val == head->next->val (4 == 4)
dummy → 1 → 2       4 → 4 → 5
            ↑       ↑---↑
           prev       head (skipping)

After skipping:
head = 5

dummy → 1 → 2 → 4 → 4 → 5
            ↑           ↑
           prev        head
Set prev->next = head to remove all 4s:
dummy → 1 → 2 → 5
            ↑   ↑
           prev  head

*/

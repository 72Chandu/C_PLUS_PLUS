/* https://leetcode.com/problems/copy-list-with-random-pointer/?envType=study-plan-v2&envId=top-interview-150
// Definition for a Node.
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*//m-1 (Using O(n) space)
class Solution {
public:
    Node* copyRandomList(Node* head) {
       if(head==NULL) return NULL;
       unordered_map<Node*,Node*>mp;//store the node of copied node and original node(key)
       Node* curr=head;//traverse on original list
       Node* prev=NULL; //travere on copied list
       Node* newHead=NULL;
       while(curr){
        Node* temp=new Node(curr->val);
        mp[curr]=temp;
        if(newHead==NULL){
            newHead=temp;
            prev=newHead;
        }else{
            prev->next=temp;
            prev=temp;
        }
        curr=curr->next;
       }
       // fill random pointer
       curr=head; //traversing orinal list
       Node* newcurr=newHead; //traversing copied list
       while(curr){
        if(curr->random==NULL){
            newcurr->random=NULL;
        }else{
            newcurr->random=mp[curr->random];
        }
        curr=curr->next;
        newcurr=newcurr->next;
       }
       return newHead;
    }

};
/*   val[nextpointer/randeompointer]
A       7[B/null] -> 13[C/null] -> 11[null/A]
head        A            B             C
            curr
  x        7[/] 
 newhead     x 
            prev
node*  A
node*  x
----------
A       7[B/null] -> 13[C/null] -> 11[null/A]
head        A            B             C
                         curr
x       7[y/] -> 13[/]
newhead   x       y
                 prev
node*  A  B
node*  x  y
------------
A       7[B/null] -> 13[C/null] -> 11[null/A]
head        A            B             C
                                       curr
x       7[y/] -> 13[z/] -> 11[/]
newhead     x     y        z
                          prev
node*  A  B  C
node*  x   y  z 

x         7[y/] -> 13[z/] -> 11[null/]
newhead      x     y           z
                              prev
node*  A  B  C
node*  x   y  z
----start filling random pointer 

A       7[B/null] -> 13[C/null] -> 11[null/A]
head        A            B             C
            curr

  x        7[y/null] -> 13[z/] -> 11[null/]
 newhead       x           y         z
            newcurr
---------
A       7[B/null] -> 13[C/null] -> 11[null/A]
head        A            B             C
                         curr

   x       7[y/null] -> 13[z/null] -> 11[null/]
 newhead       x             y           z
                          newcurr
-------
A       7[B/null] -> 13[C/null] -> 11[null/A]
head        A            B             C
                                      curr

   x       7[y/null] -> 13[z/null]  -> 11[null/A]
 newhead       x             y
                                          newcurr
this A is fill from the hep of 
node*  A  B  C
node*  x   y  z

*/

#include<iostream>
using namespace std;
    class node{
        public:
        int val;
        node*next;
        node(int data){
            val=data;
            next=NULL;
        }
    };
     void display(node*head){
            node*temp=head;
            while(temp!=NULL){
                cout<<temp->val<<"->";
                temp=temp->next;
            }
            cout<<"NULL";
        }
        void insert_at_head(node*&head,int val){
            node*new_head=new node(val);
            new_head->next=head;
            head=new_head;
        }
        void delete_alternate(node*&head){
            node*curr=head;
            while(curr!=NULL&&curr->next!=NULL){
                node*temp=curr->next;
                curr->next=curr->next->next;
                free(temp);
                curr=curr->next;
            }
        }
    int main(){
       node*head=NULL;
       insert_at_head(head,1);
       insert_at_head(head,2);
       insert_at_head(head,3);
       insert_at_head(head,4);
       insert_at_head(head,5);
       display(head);
       delete_alternate(head);
       display(head);
       return 0;
}

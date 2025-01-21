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
void insert_at_head(node*&head,int val){
    node*new_node=new node(val);
    new_node->next=head;
    head=new_node;
}
void display(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
void reverse_print(node*head){
    if(head==NULL){
        return;
    }
    reverse_print(head->next);
    cout<<head->val<<"->";
}
int main(){
    node*head=NULL;
    insert_at_head(head,1);
    insert_at_head(head,2);
    insert_at_head(head,3);
    insert_at_head(head,4);
    insert_at_head(head,5);
    display(head);
    cout<<"\nreverse\n";
    reverse_print(head);
    
}

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
    cout<<"NULL"<<endl;
}
void insert_at_end(node*&head,int values){
    node*new_node=new node(values);
    if(head==NULL){
        head=new_node;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}
node* revese(node*&head){
    node*curr=head;
    node*prev=NULL;
    while(curr!=NULL){
        node*temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
int main(){
    node*head=NULL;
    insert_at_end(head,1);
    insert_at_end(head,2);
    insert_at_end(head,3);
    insert_at_end(head,4);
    insert_at_end(head,5);
    display(head);
    node*l1=revese(head);
    display(l1);
    return 0;
}



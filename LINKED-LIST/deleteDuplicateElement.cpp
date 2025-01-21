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
        cout<<temp->next<<"->";
        temp=temp->next;
    }
}
void insert_at_head(node*head,int val){
    node*new_node=new node(val);
    new_node->next=head;
    head=new_node;
}
void insert_at_end(node*head,int val){
    node*new_node=new node(val);
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    
}
int main(){
    node*head=NULL;
    
}

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
void InserAtHead(node* &head,int val){
    node* new_node=new node(val);
    new_node->next=head;
    head=new_node;
}
void AddAtTail(node* &head,int val){
    node* new_node=new node(val);
    if(head==NULL){
        head=new_node;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }//after completing loop temp pointing to before null
    temp->next=new_node;
}
void addAtArbitrareyPos(node* &head,int val,int pos){
    node* new_node=new node(val);
    if(pos==0){
        InserAtHead(head,val);
    }
    int currrent_pos=0;
    node*temp=head;
    while(currrent_pos!=pos-1){
        temp=temp->next;
        currrent_pos++;
    }
    new_node->next=temp->next;
    temp->next=new_node;//if we write it in above then we lost the node location from pos to end
}
void updationAtPos(node* &head,int pos,int val){
     node* new_node=new node(val);
    int currrent_pos=0;
    node*temp=head;
    while(currrent_pos!=pos){
        temp=temp->next;
        currrent_pos++;
    }
    temp->val=val;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }//after completing temp pointing to null
    cout<<"NULL"<<endl;
}
int main(){
    node*head=NULL;
    InserAtHead(head,2);
    display(head);
    cout<<"insert node at head"<<endl;
    InserAtHead(head,1);
    display(head);
    cout<<"insert node at end"<<endl;
    AddAtTail(head,3);
    display(head);
    cout<<"add at pos=2"<<endl;
    addAtArbitrareyPos(head,5,2);
    display(head);
    cout<<"udate the val 6 to pos=1"<<endl;
    updationAtPos(head,1,6);
    display(head);
    
}

#include<iostream>
#include<vector>
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
node*create_a_ll(vector<int>&values){
    node*dummy=new node(0);
    node*temp=dummy;
    for(int ele:values){
        temp->next=new node(ele);
        temp=temp->next;
    }
    return dummy->next;
}
node*delete_at_head(node*&head){
    if(head==NULL){
        return NULL;
    }
    node*temp=head;
    node*new_head=head->next;
    delete temp;
    return new_head;
}
node*delete_at_end(node*&head){
    if(head==NULL||head->next==NULL){
        delete head;
        return NULL;
    }
    node*second_last=head;
    while(second_last->next->next!=NULL){
        second_last=second_last->next;
    }
    node*temp=second_last->next;
    delete temp;
    second_last->next=NULL;
    return head;
}
node*delete_at_arbitrary_pos(node*head,int pos){
    if(pos==0){
        delete_at_head(head);
        return 0;
    }
    int curr_pos=0;
    node*prev=head;
    while(curr_pos!=pos-1){
        prev=prev->next;
        curr_pos++;
    }//aftert loop prev is at pos-1
    node*temp=prev->next;//temp point to pos
    prev->next=prev->next->next;//connecting pos-1 ele to pos+1 ele
    delete temp;
    return head;
}
int main(){
    vector<int>v={1,2,3,4,5,6,7};
    cout<<"original"<<endl;
    node*l1=create_a_ll(v);
    display(l1);
    cout<<"\nafter deletion at head"<<endl;
    node*l1d=delete_at_head(l1);
    display(l1d);
    cout<<"\nafter deletion at end"<<endl;
    node*l1de=delete_at_end(l1d);
    display(l1de);
    cout<<"\ndelete at arbitrary position 2"<<endl;
    node*l1dea=delete_at_arbitrary_pos(l1de,2);
    display(l1dea);
    return 0;
}

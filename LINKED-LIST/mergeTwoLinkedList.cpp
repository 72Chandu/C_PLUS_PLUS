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
void diaplay(node*head){
    if(head==NULL){
        return;
    }
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
node*create_ll(vector<int>&values){
    node*dummy=new node(-1);
    node*temp=dummy;
    for(int ele:values){
     temp->next=new node(ele);
     temp=temp->next;
    }
    return dummy->next;
}
node*mergeTwo_ll(node*head1,node*head2){
    node*new_head=new node(-1);
    node*ptr1=head1;
    node*ptr2=head2;
    node*ptr3=new_head;
    while(ptr2&&ptr1!=NULL){
        if((ptr1->val)>(ptr2->val)){
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        else{
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        ptr3=ptr3->next;
        if(ptr1!=NULL){
            ptr3->next=ptr1;
        }
        else{
            ptr3->next=ptr2;
        }
    }
    return new_head->next;
}
int main(){
    vector<int>v1={1,2,3,4,5};
    vector<int>v2={9,8,7,6,5};
    node*l1=create_ll(v1);
    node*l2=create_ll(v2);
    node*newll=mergeTwo_ll(l1,l2);
    diaplay(l1);
    cout<<"\n";
    //diaplay(l2);
     cout<<"\n";
    diaplay(newll);
}

#include<iostream>
using namespace std;
#include<vector>
class node{
    public:
    int val;
    node*next;
    node(int data){
        val=data;
        next=NULL;
    }
};
node*reverse(node*&head,int k){
    node*prev=NULL;
    node*curr=head;
    int count=0;
    while(curr!=NULL&&count<k){
        node*temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        count++;
    }
    if(curr!=NULL){
        node*new_node=reverse(curr,k);
        head->next=new_node;
    }
    return prev;
}
node*createAll(vector<int>&v){
    node*dummy=new node(0);
    node*temp=dummy;
    for(int ele:v){
        temp->next=new node(ele);
        temp=temp->next;
    }
    return dummy->next;
}
void display(node *head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
int main(){
    int n;
    cout<<"enter the no of nodes to be reverse ";
    cin>>n;
    vector<int>v={1,2,3,4};
    node*linkedlist=createAll(v);
    display(linkedlist);
    printf("\nafter reversing\n");
    node*ans=reverse(linkedlist,n);
    display(ans);
    return 0;
}

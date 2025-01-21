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
node*create_a_ll(vector<int>&v){
    node*dummy=new node(0);
    node*temp=dummy;
    for(int ele:v){
        temp->next=new node(ele);
        temp=temp->next;
    }
    return dummy->next;
}
void display(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
bool check_equality(node*head1,node*head2){
    node*ptr1=head1;
    node*ptr2=head2;
    while(ptr1!=NULL&&ptr2!=NULL){
        if(ptr1->val!=ptr2->val){
            return false;
        }
        else{
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
    return (ptr1==NULL&&ptr2==NULL);
}
int main(){
    vector<int>v1={1,2,3,4,5};
    vector<int>v2={1,2,3,4,5};
    node*l1=create_a_ll(v1);
    node*l2=create_a_ll(v2);
    display(l1);
    display(l2);
    int check=check_equality(l1,l2);
    if(check==true){
        cout<<"equal";
    }
    else{
        cout<<"not equal";
    }
    return 0;
}

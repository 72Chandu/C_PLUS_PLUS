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
    node*addTwoLL(node*L1,node*L2){
        node*sum_node=new node(0);//empty node 
        node* temp=sum_node;
        int carry=0;
        while(L1!=NULL || L2!=NULL ||carry){
            int sum=0;
            if(L1!=NULL){
                sum+=L1->val;
                L1=L1->next;
            }
            if(L2!=NULL){
                sum+=L2->val;
                L2=L2->next;
            }
            sum+=carry;
            carry=sum/10;
            node*sum_node=new node(sum%10);//pushing element in empty node
            temp->next=sum_node;
            temp=temp->next;
        }
        return sum_node->next;
    }
    node*create_A_LL(vector<int>&values){//creating a liked list
        node*dummy=new node(0);//creating a empty node
        node*temp=dummy;
        for(int val:values){
            temp->next=new node(val);//pushing the element into empty node 
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
        cout<<"NULL";
    }
    int main(){
      vector<int>val1={2,4,3};//creating two vector
      vector<int>val2={5,6,4};
      node*L1=create_A_LL(val1);//creating two ll
      node*L2=create_A_LL(val2);
      node*result=addTwoLL(L1,L2);//add two ll
      display(result);//print result
      return 0;
    }

#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node*next; 
};
struct node*head=NULL;
void create_ll(int n){
    for(int i=0;i<n;i++){
        struct node*new_node=(struct node*)malloc(sizeof(struct node));
        printf("enter the data for node %d",i+1);
        scanf("%d",&new_node->val);
        new_node->next=NULL;
        if(head==NULL){
          head=new_node;
        }
        else{
            struct node*temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=new_node;
        }
    }
}
void display(){
    struct node*temp=head;
    if(head==NULL)return;
    while(temp!=NULL){
        printf("%d->",temp->val);
        temp=temp->next;
    }
    printf("NULL");
}
void add_at_head(int val){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->val=val;
    new_node->next=head;
    head=new_node;
}
void add_at_end(int val){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->val=val;
    struct node*temp=head;
    if(head==NULL){
        head=new_node;
    }
   while(temp->next!=NULL){
    temp=temp->next;
   }
    temp->next=new_node;
    new_node->next=NULL;
}
void add_at_pos(int val,int pos){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->val=val;
    struct node*temp=head;
    if(pos==1){
        add_at_head(val);
        return;
    }
    int curr_pos=0;
    while(curr_pos!=pos-1){
        temp=temp->next;
        curr_pos++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}
void delete_at_head(){
    if(head==NULL)return;
    struct node*temp=head;
    head=temp->next;
    free(temp);
}
void delete_at_end(){
    struct node*curr=head;
    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    struct node*temp=curr->next;
    curr->next=NULL;
    free(temp);
}
void delete_at_pos(int pos){
    if(pos==1){
        delete_at_head();
        return;
    }
    struct node*curr=head;
    int curr_pos=0;
    while(curr_pos!=pos-1){
        curr=curr->next;
        curr_pos++;
    }
    struct node*temp=curr->next;
    curr->next=curr->next->next;
    free(temp);
}
void reverse_ll(){
    if(head==NULL)return;
    struct node*prev=NULL;
    struct node*curr=head;
    while(curr!=NULL){
        struct node*temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head=prev;
}
int main(){
    int n;
    printf("enter the no of nodes");
    scanf("%d",&n);
    create_ll(n);printf("\n");
    display();
    add_at_head(6);printf("\n");
    display();
    add_at_end(12);printf("\n");
    display();
    add_at_pos(45,3);printf("\n");
    display();
    delete_at_head();printf("\n");
    display();
    delete_at_end();printf("\n");
    display();
    delete_at_pos(2);printf("\n");
    display();
    reverse_ll();printf("\n");
    display();
}

#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*prev;
    struct node*next;
    int val;
};
struct node *head=NULL;
void display(){
    struct node*temp=head;
    if(head==NULL)return;
    while(temp!=NULL){
        printf("%d<->",temp->val);
        temp=temp->next;
    }
    printf("NULL");
}
void create_dll(int n){
    struct node*temp=head;
    for(int i=0;i<n;i++){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&new_node->val);
    new_node->prev=NULL;
    new_node->next=NULL;
    if(head==NULL){
        temp=head=new_node;
    }
    else{
        temp->next=new_node;
        new_node->prev=temp;
        temp=new_node;
    }
    
    }
}
void add_at_head(int x){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->val=x;
    struct node*temp=head;
    if(head==NULL){
        temp=head=new_node;
    }
    else{
        new_node->next=head;
        head->prev=new_node;
        new_node->prev=NULL;
        head=new_node;
    }
}
void add_at_end(int x){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->val=x;
    struct node*temp=head;
    if(head==NULL){
        temp=head=new_node;
    }
   while(temp->next!=NULL){
       temp=temp->next;
   }
   temp->next=new_node;
   new_node->prev=temp;
   new_node->next=NULL;
}
void add_at_pos(int x,int pos){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->val=x;
    struct node*temp=head;
    int count=1;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
       new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        if (new_node->next != NULL) {
            new_node->next->prev = new_node;
        }
}
void delete_at_head(){
    struct node*temp=head;
    head=head->next;
    head->prev=NULL;
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
    if (head == NULL) {
            printf("List is empty. Cannot delete from an empty list.");
            return;
        }
        if (pos == 1) {
            delete_at_head();
            return;
        }
        struct node* temp = head;
        int count = 1;
        while (count < pos - 1 && temp != NULL) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL || temp->next == NULL) {
            printf("Position out of bounds. Cannot delete.");
            return;
        }
        struct node* node_to_delete = temp->next;
        temp->next = node_to_delete->next;
        if (node_to_delete->next != NULL) {
            node_to_delete->next->prev = temp;
        }
        free(node_to_delete);
   }
   void reverse_dll(){
       struct node*curr=head;
       while(curr!=NULL){
           struct node*new=curr->next;
           curr->next=curr->prev;
           curr->prev=new;
       }
       head=curr;
   }
int main(){
    int n;
    printf("enter the no of nodes");
    scanf("%d",&n);
    create_dll(n);printf("\n");
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
    reverse_dll();
    display();
}








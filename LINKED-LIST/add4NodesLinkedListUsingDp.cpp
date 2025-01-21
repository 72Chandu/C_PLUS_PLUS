#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int main(){
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    if(head==NULL){
        printf("memory allocation is failed");
        return 1;
    }
   head->data=1;
   head->next=NULL;
   struct Node*curr=head;
   for(int i=0;i<4;i++){
       struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
         if(newNode==NULL){
           printf("memory allocation is failed");
           return 1;
       }
       newNode->data=i;
       newNode->next=NULL;
       curr->next=newNode;//linking
       curr=newNode;
       
   }
    struct Node* temp=head;//display
   while(temp!=NULL){
       printf("%d->",temp->data);
       temp=temp->next;
   }
   printf("NULL");
   temp = head;
   while (temp != NULL) {//free the memory
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
}

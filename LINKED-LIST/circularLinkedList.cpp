#include <stdio.h>
#include <stdlib.h>
struct node {
    int val;
    struct node* next;
};
struct node* head = NULL;
void create_c_ll(int n) {
    for (int i = 0; i < n; i++) {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        printf("enter the data for node %d: ", i + 1);
        scanf("%d", &new_node->val);
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            head->next = head; // Make it circular
        } else {
            struct node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = head;
        }
    }
}

void display() {
    struct node* temp = head;
    if (head == NULL) return;
    do {
        printf("%d->", temp->val);
        temp = temp->next;
    } while (temp != head);
}
void add_at_head(int val) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = val;
    if (head == NULL) {
        head = new_node;
        head->next = head;
        return;
    }
    struct node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    new_node->next = head;
    head = new_node;
    tail->next = head;
}
void add_at_end(int val) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = val;
    if (head == NULL) {
        head = new_node;
        head->next = head;
        return;
    }
    struct node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    tail->next = new_node;
    new_node->next = head;
}
void add_at_pos(int val, int pos) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = val;
    if (pos == 1) {
        add_at_head(val);
        return;
    }
    struct node* temp = head;
    int curr_pos = 1;
    while (curr_pos < pos - 1 && temp->next != head) {
        temp = temp->next;
        curr_pos++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}
void delete_at_head() {
    if (head == NULL)
        return;
    struct node* curr = head;
    struct node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    head = head->next;
    tail->next = head;
    free(curr);
}
void delete_at_end() {
    if (head == NULL)
        return;
    struct node* curr = head;
    struct node* prev = NULL;
    while (curr->next != head) {
        prev = curr;
        curr = curr->next;
    }
    if (prev != NULL) {
        prev->next = head;
    } else {
        head = NULL;
    }
    free(curr);
}
void delete_at_pos(int pos) {
    if (pos == 1) {
        delete_at_head();
        return;
    }
    struct node* curr = head;
    struct node* prev = NULL;
    int curr_pos = 1;

    while (curr_pos < pos && curr->next != head) {
        prev = curr;
        curr = curr->next;
        curr_pos++;
    }

    if (curr_pos == pos) {
        prev->next = curr->next;
        free(curr);
    }
}

int main() {
    int n;
    printf("enter the no of nodes: ");
    scanf("%d", &n);
    create_c_ll(n);
    printf("\n");
    display();
    add_at_head(6);
    printf("\n");
    display();
    add_at_end(12);
    printf("\n");
    display();
    add_at_pos(45, 3);
    printf("\n");
    display();
    delete_at_head();
    printf("\n");
    display();
    delete_at_end();
    printf("\n");
    display();
    delete_at_pos(2);
    printf("\n");
    display();
}



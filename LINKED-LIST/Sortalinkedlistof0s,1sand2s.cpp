//https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/0
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        if(!head) return head;
        Node* head0 = new Node(0);
        Node* head1 = new Node(0);
        Node* head2 = new Node(0);
        Node* p0 = head0;
        Node* p1 = head1;
        Node* p2 = head2;
        Node* curr = head;
        while(curr) {
            if(curr->data == 0) {
                p0->next = curr;
                p0 = p0->next;
            } else if(curr->data == 1) {
                p1->next = curr;
                p1 = p1->next;
            } else {
                p2->next = curr;
                p2 = p2->next;
            }
            curr = curr->next;
        }
        
        // Connect the three lists
        p0->next = (head1->next) ? (head1->next) : (head2->next);
        p1->next = head2->next;
        p2->next = nullptr;
        
        // Updated head
        head = head0->next;
        
        // Cleanup
        delete head0;
        delete head1;
        delete head2;
        
        return head;
    }
};

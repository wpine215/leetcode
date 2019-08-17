#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main() {
    // Example LL: 2->4->3

    // Initialize cursor
    ListNode* cursor;

    // Create head
    ListNode* head = new ListNode(2);
    
    // Create second element
    head->next = new ListNode(4);
    cursor = head->next;

    // Create third element
    cursor->next = new ListNode(3);
    cursor = cursor->next;

    // Iterate over linked list and print
    ListNode* temp = head;
    while(temp != NULL) {
        cout << temp->val << endl;
        temp = temp->next;
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum;
        int carry = (l1->val + l2->val) / 10;
        ListNode* head = new ListNode((l1->val + l2->val) % 10);
        ListNode* curr = head;
        l1 = l1->next;
        l2 = l2->next;

        while (l1 != NULL) {
            if (l2 != NULL) {
                sum = (l1->val + l2->val + carry) % 10;
                carry = (l1->val + l2->val + carry) / 10;
                curr->next = new ListNode(sum);
                curr = curr->next;
                l1 = l1->next;
                l2 = l2->next;
            } else {
                sum = (l1->val + carry) % 10;
                carry = 0;
                curr->next = new ListNode(sum);
                curr = curr->next;
                l1 = l1->next;
            }         
        }

        while(l2 != NULL) {
            sum = (l2->val + carry) % 10;
            carry = 0;
            curr->next = new ListNode(sum);
            curr = curr->next;
            l2 = l2->next;
        }

        return head;
    }
};
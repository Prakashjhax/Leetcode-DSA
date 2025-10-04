/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to act as the head of the resulting list
        ListNode* dummyHead = new ListNode(0);
        // 'current' will build the list, starting from the dummyHead
        ListNode* current = dummyHead;
        // Pointers to traverse the input lists
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        // The carry from the previous addition
        int carry = 0;

        // Continue the loop as long as there are digits in either list or a carry remains
        while (p1 != nullptr || p2 != nullptr || carry != 0) {
            // Get the value of the current digit, or 0 if the list is exhausted
            int val1 = (p1 != nullptr) ? p1->val : 0;
            int val2 = (p2 != nullptr) ? p2->val : 0;

            // Calculate the total sum for the current position
            int sum = val1 + val2 + carry;

            // The new digit for the result list is the remainder (the ones place)
            int digit = sum % 10;
            // The new carry is the quotient (the tens place)
            carry = sum / 10;

            // Create a new node with the calculated digit and append it
            current->next = new ListNode(digit);
            // Move the current pointer to the newly added node
            current = current->next;

            // Move the input list pointers forward if they are not null
            if (p1 != nullptr) {
                p1 = p1->next;
            }
            if (p2 != nullptr) {
                p2 = p2->next;
            }
        }

        // The result is the node immediately after the dummy head
        ListNode* result = dummyHead->next;
        // Free the dummy head node's memory
        delete dummyHead;

        return result;
    }
};
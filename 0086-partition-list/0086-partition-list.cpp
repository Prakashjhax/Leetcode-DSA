/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Two dummy heads for two separate lists
        ListNode* beforeHead = new ListNode(0);
        ListNode* afterHead = new ListNode(0);
        
        // Pointers to build the two lists
        ListNode* before = beforeHead;
        ListNode* after = afterHead;
        
        // Traverse the original list
        while (head) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        
        // Important: terminate the after list
        after->next = nullptr;
        
        // Connect the two lists
        before->next = afterHead->next;
        
        // Return the start of the new list
        return beforeHead->next;
    }
};

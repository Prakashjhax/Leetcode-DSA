class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // Dummy node for sorted list
        ListNode* dummy = new ListNode(0);

        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // next node save

            // find correct position in sorted list
            ListNode* prev = dummy;
            while (prev->next != nullptr && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // insert curr
            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode;
        }
        return dummy->next;
    }
};

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(0);  // dummy node before head
        dummy->next = head;

        ListNode* prev = dummy;     // last non-duplicate node
        ListNode* curr = head;      // current pointer

        while (curr) {
            bool duplicate = false;

            // Skip all duplicates
            while (curr->next && curr->val == curr->next->val) {
                duplicate = true;
                curr = curr->next;
            }

            if (duplicate) {
                // Skip entire duplicate group
                prev->next = curr->next;
            } else {
                // Move prev only if no duplicate found
                prev = prev->next;
            }

            curr = curr->next;
        }

        return dummy->next;
    }
};

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
    ListNode* swapPairs(ListNode* head) {
        // Base case: 0 or 1 node
        if (!head || !head->next)
            return head;

        // Nodes to be swapped
        ListNode* first = head;
        ListNode* second = head->next;

        // Recursive call for remaining list
        first->next = swapPairs(second->next);

        // Swap
        second->next = first;

        // New head
        return second;
    }
};

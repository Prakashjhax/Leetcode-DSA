/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = NULL, *second = NULL, *prev = NULL;
        TreeNode *curr = root;

        while (curr) {

            if (!curr->left) {
                // Check violation
                if (prev && prev->val > curr->val) {
                    if (!first) first = prev;
                    second = curr;
                }
                prev = curr;

                curr = curr->right;
            } 
            
            else {
                // Find inorder predecessor
                TreeNode* temp = curr->left;
                while (temp->right && temp->right != curr)
                    temp = temp->right;

                if (!temp->right) {
                    temp->right = curr;        // create thread
                    curr = curr->left;
                } else {
                    temp->right = NULL;        // remove thread

                    // Check violation
                    if (prev && prev->val > curr->val) {
                        if (!first) first = prev;
                        second = curr;
                    }
                    prev = curr;

                    curr = curr->right;
                }
            }
        }

        // Swap the misplaced node values
        swap(first->val, second->val);
    }
};

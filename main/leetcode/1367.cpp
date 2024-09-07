#include "lib/leetcode_ds.h"

class Solution {
  public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        // By virtue that an empty subpath should exist within a tree
        if (head == nullptr) {
            return true;
        }

        if (root == nullptr) {
            return false;
        }

        bool result = false;

        if (head->val == root->val) {
            result = dfs(head, root);
        }

        return result || isSubPath(head, root->left) ||
               isSubPath(head, root->right);
    }

    bool dfs(ListNode* head, TreeNode* root) {
        if (head == nullptr) {
            return true;
        }

        if (root == nullptr || head->val != root->val) {
            return false;
        }

        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
};

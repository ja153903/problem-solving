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

        if (head->val == root->val && dfs(head, root)) {
            return true;
        }

        return isSubPath(head, root->left) || isSubPath(head, root->right);
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

/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
 * Runtime: 24 ms (47.17%)
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (max(p->val, q->val) < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (min(p->val, q->val) > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }

        return NULL;
    };
};

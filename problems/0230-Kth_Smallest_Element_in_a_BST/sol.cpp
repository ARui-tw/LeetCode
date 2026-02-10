/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/kth-smallest-element-in-a-bst
 * Runtime: 0 ms (100.00%)
 */

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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* res;
        int cur = 0;
        auto dfs = [&](this const auto& self, TreeNode* node) {
            if (!node) return;
            
            self(node->left);
            if (++cur == k) res = node;
            self(node->right);
        };

        dfs(root);

        return res->val;
    }
};

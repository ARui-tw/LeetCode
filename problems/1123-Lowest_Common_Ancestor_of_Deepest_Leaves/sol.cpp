/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }

    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root) return {NULL, 0};

        auto [ln, ld] = dfs(root->left);
        auto [rn, rd] = dfs(root->right);

        if (ld == rd) return {root, ld + 1};
        else if (ld > rd) return {ln, ld + 1};
        else return {rn, rd + 1};
    }
};

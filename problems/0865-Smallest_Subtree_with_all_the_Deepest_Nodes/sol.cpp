/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        auto dfs = [&](this const auto& self, TreeNode* cur) -> pair<int, TreeNode*> {
            if (!cur) return {-1, NULL};
            auto [ldepth, lnode] = self(cur->left);
            auto [rdepth, rnode] = self(cur->right);
            int curDepth = max(ldepth, rdepth) + 1;

            if (ldepth == rdepth) return {curDepth, cur};
            if (ldepth > rdepth) return {curDepth, lnode};
            return {curDepth, rnode};
        };

        return dfs(root).second;
    }
};

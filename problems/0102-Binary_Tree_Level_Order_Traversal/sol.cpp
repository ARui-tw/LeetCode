/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/binary-tree-level-order-traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> res;
        if (!root) return res;

        qu.push(root);
        while (!qu.empty()) {
            int n = qu.size();
            vector<int> cur;

            while (n--) {
                auto top = qu.front();
                qu.pop();
                cur.push_back(top->val);

                if (top->left) qu.push(top->left);
                if (top->right) qu.push(top->right);
            }
            
            res.push_back(cur);
        }

        return res;
    }
};

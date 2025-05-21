/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/binary-tree-right-side-view
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if (!root) return res;

        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            int n = qu.size();
            int last;
            while (n--) {
                auto top = qu.front();
                last = top->val;
                qu.pop();

                if (top->left) qu.push(top->left);
                if (top->right) qu.push(top->right);
            }
            res.push_back(last);
        }

        return res;
    }
};

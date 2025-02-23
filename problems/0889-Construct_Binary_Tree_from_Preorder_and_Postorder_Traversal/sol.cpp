/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    vector<int> pre, post;
    int preP, postP;
    int n;

public:
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        this->pre = preorder;
        this->post = postorder;
        this->preP = 1;
        this->postP = 0;
        this->n = preorder.size();

        TreeNode* root = new TreeNode(pre[0]);
        if (pre[0] != post[0]) dfs(root);
        
        return root;
    }

    void dfs(TreeNode* cur) {
        TreeNode* n = new TreeNode(pre[preP]);
        cur->left = n;
        if (pre[preP++] != post[postP]) {
            dfs(n);
        } else {
            postP++;
        }
        if (post[postP] == cur->val) {
            postP++;
            return;
        }

        n = new TreeNode(pre[preP]);
        cur->right = n;
        if (pre[preP++] != post[postP]) {
            dfs(n);
        } else {
            postP++;
        }
        if (post[postP] == cur->val) {
            postP++;
        }
    }
};

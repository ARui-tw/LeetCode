/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree
 * Runtime: 10 ms (62.24%)
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
class FindElements {
    unordered_set<int> vals;
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        vals.insert(0);
        dfs(root->left, 0, true);
        dfs(root->right, 0, false);
    }
    
    bool find(int target) {
        return vals.count(target);
    }
    void dfs(TreeNode* cur, int parentVal, bool isLeft) {
        if (!cur) return;
        cur->val = isLeft ? parentVal * 2 + 1 : parentVal * 2 + 2;
        vals.insert(cur->val);
        dfs(cur->left, cur->val, true);
        dfs(cur->right, cur->val, false);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

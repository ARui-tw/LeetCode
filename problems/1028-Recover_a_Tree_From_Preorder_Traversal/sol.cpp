/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal
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
    int pointer;
    string s;
    int n;
public:
    TreeNode* recoverFromPreorder(string traversal) {
        pointer = 0;
        this->s = traversal;
        this->n = traversal.size();
        
        while (pointer < n && traversal[pointer] != '-') {
            pointer++;
        }

        string subString = traversal.substr(0, pointer);

        TreeNode* root = new TreeNode(stoi(subString));

        dfs(root, 0);

        return root;
    }

    int a(int start, int end) {
        int res = 0;
        for (int i = start; i < end; i++) {
            res = res * 10 + (s[i] - '0');
        }
        return res;
    }

    int dfs(TreeNode* cur, int curLevel) {
        int nextLevel = 0;
        int prevPointer = pointer;
        int rightNextLevel;

        while (s[pointer] == '-') {
            pointer++;
            nextLevel++;
        }

        if (nextLevel - curLevel == 1) {
            int start = pointer;
            while (pointer < n && s[pointer] != '-') pointer++;

            cur->left= new TreeNode(a(start, pointer));
            nextLevel = dfs(cur->left, curLevel+1);
        } else {
            return nextLevel;
        }

        if (nextLevel - curLevel == 1) {
            int start = pointer;
            while (pointer < n && s[pointer] != '-') pointer++;

            cur->right= new TreeNode(a(start, pointer));
            nextLevel = dfs(cur->right, curLevel+1);
        }

        return nextLevel;
    }
};

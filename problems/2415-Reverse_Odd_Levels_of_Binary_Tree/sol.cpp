/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree
 * Runtime: 2 ms (53.45%)
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int ma = 1;
        int level = 1;
        int counter = 0;

        queue<TreeNode*> qu;
        queue<int> reverse;
        stack<TreeNode*> sta;
        qu.push(root);

        while (!qu.empty()) {
            counter++;
            
            auto cur = qu.front();
            qu.pop();

            if (cur->left) {
                qu.push(cur->left);
                qu.push(cur->right);
            }

            if (level %2 == 0) {
                reverse.push(cur->val);
                sta.push(cur);
            }

            // printf("ma: %d, level: %d, counter %d
", ma, level, counter);

            if (ma == counter) {
                if (level % 2 == 0) {
                    while (!reverse.empty()) {
                        auto ne = reverse.front();
                        auto th = sta.top();

                        th->val = ne;

                        reverse.pop();
                        sta.pop();
                    }
                }

                level++;
                ma *= 2;
                counter = 0;
            }
        }

        return root;
    }
};

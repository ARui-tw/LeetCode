/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level
 * Runtime: 105 ms (53.96%)
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
    int minimumOperations(TreeNode* root) {
        queue<pair<TreeNode*, long long>> qu;
        qu.push({root, 0});
        long long cur_level = 0;
        vector<int> vec;
        vector<int> vec_sorted;
        unordered_map<int, int> um;
        int res = 0;
        while (!qu.empty()) {
            auto [cur, level] = qu.front();
            qu.pop();

            if (cur_level != level) {
                for (int i = 0; i < vec.size(); i++) {
                    vec_sorted.push_back(vec[i]);
                    um[vec[i]] = i;
                }
                sort(vec_sorted.begin(), vec_sorted.end());

                for (int i = 0; i < vec.size(); i++) {
                    int val = vec_sorted[i];
                    if (vec[i] != val) {
                        int idx = um[val];
                        vec[idx] = vec[i];
                        um[vec[i]] = idx;
                        res++;
                    }
                }
                
                vec.clear();
                vec_sorted.clear();
                cur_level = level;
            }

            vec.push_back(cur->val);
            if (cur->left) qu.push({cur->left, level+1});

            if (cur->right) qu.push({cur->right, level+1});
        }

        for (int i = 0; i < vec.size(); i++) {
            vec_sorted.push_back(vec[i]);
            um[vec[i]] = i;
        }
        sort(vec_sorted.begin(), vec_sorted.end());

        for (int i = 0; i < vec.size(); i++) {
            int val = vec_sorted[i];
            if (vec[i] != val) {
                int idx = um[val];
                vec[idx] = vec[i];
                um[vec[i]] = idx;
                res++;
            }
        }
        

        return res;
    }
};

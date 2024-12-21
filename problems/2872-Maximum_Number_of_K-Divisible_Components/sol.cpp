/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-number-of-k-divisible-components
 * Runtime: 103 ms (77.85%)
 */
\nclass Solution {
public:
    struct node {
        long long val;
        vector<node*> child;
    };

    long long ans;
    int K;

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<node*> nodes;
        ans = 1;
        K = k;
        
        for (int i = 0; i < n; i++) {
            node* tmp = new node();

            tmp->val = values[i];
            nodes.push_back(tmp);
        }

        for (auto& e : edges) {
            nodes[e[0]]->child.push_back(nodes[e[1]]);
            nodes[e[1]]->child.push_back(nodes[e[0]]);
        }

        // for (auto n : nodes) {
        //     printf("val: %d, size: %d\n", n->val, n->child.size());
        // }

        node* root = nodes[0];

        for (auto c : root->child) {
            if (c == root) continue;
            dfs(c, root);
        }
        
        return ans;
    }

    void dfs(node* cur, node* parent) {
        for (auto c : cur->child) {
            if (c == parent) continue;
            dfs(c, cur);
        }

        if (cur->val % K == 0) {
            ans++;
        } else {
            parent->val += cur->val;
        }
    }
};

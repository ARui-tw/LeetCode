/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-number-of-k-divisible-components
 * Runtime: 93 ms (88.26%)
 */

class Solution {
    struct Node {
        int idx;
        vector<Node*> nxt;
    };
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<Node*> nodes(n);
        vector<bool> seen(n, false);
        int res = 0;
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();
            nodes[i]->idx = i;
        }
        for (auto& edge : edges) {
            nodes[edge[0]]->nxt.push_back(nodes[edge[1]]);
            nodes[edge[1]]->nxt.push_back(nodes[edge[0]]);
        }

        auto dfs = [&](this const auto& self, Node* cur) -> int {
            seen[cur->idx] = true;
            long long curVal = values[cur->idx];
            for (auto& child : cur->nxt) {
                if (!seen[child->idx]) {
                    curVal += self(child);
                    curVal %= k;
                }
            }

            if (curVal % k == 0) {
                res++;
                return 0;
            } else {
                return curVal;
            }
        };

        dfs(nodes[0]);

        return res == 0 ? 1 : res;
    }
};

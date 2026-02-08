/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/minimum-height-trees
 * Runtime: 37 ms (70.28%)
 */

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) { 
        if (n == 1) return {0};
        vector<int> neiCnt(n, 0);
        vector<vector<int>> neis(n);
        queue<int> qu;
        int cnt = 0;

        for (auto& edge : edges) {
            neiCnt[edge[0]]++;
            neiCnt[edge[1]]++;

            neis[edge[0]].push_back(edge[1]);
            neis[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            if (neiCnt[i] == 1) {
                qu.push(i);
            }
        }

        while (qu.size() + cnt != n) {
            int size = qu.size();
            while (size--) {
                int top = qu.front();
                qu.pop();
                cnt++;
                for (auto& nei : neis[top]) {
                    if (--neiCnt[nei] == 1) {
                        qu.push(nei);
                    }
                }
            }
        }

        vector<int> res;
        while (!qu.empty()) {
            res.push_back(qu.front());
            qu.pop();
        }

        return res;
    }
};

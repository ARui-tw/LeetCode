/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-the-number-of-complete-components
 * Runtime: 27 ms (87.63%)
 */

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> nei(n, vector<int>());
        vector<bool> visited(n, false);
        int res = 0;

        for (auto& edge : edges) {
            nei[edge[0]].push_back(edge[1]);
            nei[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            queue<int> qu;
            int link = nei[i].size();
            int count = 0;
            bool complete = true;

            qu.push(i);
            visited[i] = true;

            while (!qu.empty()) {
                int top = qu.front();
                qu.pop();
                count++;
                for (auto& ne : nei[top]) {
                    if (!visited[ne]) {
                        visited[ne] = true;
                        qu.push(ne);
                        if (nei[ne].size() != link) complete = false;
                    }
                }
            }
            // printf("count: %d, link: %d\n", count, link);
            if (complete && (count == link + 1)) res++;
        }

        return res;
    }
};

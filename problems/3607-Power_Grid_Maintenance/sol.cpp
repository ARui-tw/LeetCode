/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/power-grid-maintenance
 * Runtime: 327 ms (60.24%)
 */

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> root(c + 1);
        iota(root.begin(), root.end(), 0);

        vector<int> res;
        unordered_set<int> isDown;
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> umpq;

        auto find = [&](this const auto& self, int i) -> int {
            if (root[i] == i) return i;
            return (root[i] = self(root[i]));
        };

        auto merge = [&](int x, int y) {
            x = find(x);
            y = find(y);
            if (x != y) {
                if (x < y) {
                    swap(x, y);
                }
            }
            root[x] = y;
        };

        for (auto& connection : connections) {
            merge(connection[0], connection[1]);
        }

        for (int i = 1; i <= c; i++) {
            umpq[find(i)].push(i);
        }

        for (auto q : queries) {
            if (q[0] == 1) {
                if (!isDown.count(q[1])) {
                    res.push_back(q[1]);
                } else {
                    auto& pq = umpq[find(q[1])];
                    while (!pq.empty()) {
                        int top = pq.top();
                        if (!isDown.count(top)) {
                            res.push_back(top);
                            break;
                        } else {
                            pq.pop();
                        }
                    }
                    if (pq.empty()) res.push_back(-1);
                }
            } else {
                isDown.insert(q[1]);
            }
        }

       return res;
    }
};

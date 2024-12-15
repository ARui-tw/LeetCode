/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-average-pass-ratio
 * Runtime: 273ms (93.16%)
 */

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, vector<int>*>> pq;
        long long full = 0;

        for (auto& cla : classes) {
            if (cla[0] == cla[1])
                full++;
            else {
                double diff = ((cla[0] + 1) / (double)(cla[1] + 1)) -
                              (cla[0] / (double)cla[1]);
                pq.push({diff, &cla});
            }
        }

        if (!pq.empty())
            while (extraStudents--) {
                auto [a, b] = pq.top();
                auto& t = *b;
                t[0]++;
                t[1]++;
                double diff = ((t[0] + 1) / (double)(t[1] + 1)) -
                            (t[0] / (double)t[1]);
                pq.pop();
                pq.push({diff, b});
            }

        double sum = 0;
        while (pq.size()) {
            auto [a, b] = pq.top();
            auto& t = *b;
            sum += t[0] / (double)t[1];
            pq.pop();
        }

        sum += full;
        return sum / (double)classes.size();
    }
};

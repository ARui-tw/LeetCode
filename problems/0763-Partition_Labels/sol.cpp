/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/partition-labels
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> v(26, -1);
        vector<int> res;

        for (int i = 0; i < n; i++) {
            v[s[i] - 'a'] = i;
        }

        int end = 0;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            end = max(end, v[s[i] - 'a']);
            if (end == i) {
                end++;
                res.push_back(i - prev);
                prev = i;
            }
        }

        return res;
    }
};

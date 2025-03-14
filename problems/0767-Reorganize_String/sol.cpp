/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/reorganize-string
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> vol(26, 0);
        priority_queue<pair<int, char>> pq;
        string res = "";
        char prev = '.';

        for (auto& c : s) vol[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (vol[i])
                pq.push({vol[i], 'a' + i});
        }

        while (!pq.empty()) {
            auto [count, c] = pq.top();
            pq.pop();
            if (c == prev) {
                if (pq.empty()) return "";
                auto [count2, c2] = pq.top();
                pq.pop();
                pq.push({count, c});
                count = count2;
                c = c2;
            }

            res += c;
            prev = c;
            if (--count) pq.push({count, c});
        }

        return res;
    }
};

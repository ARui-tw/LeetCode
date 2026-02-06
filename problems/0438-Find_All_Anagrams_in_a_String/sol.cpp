/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/find-all-anagrams-in-a-string
 * Runtime: 7 ms (48.49%)
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_set<char> us;
        unordered_map<char, int> um;
        long rem = p.size();
        vector<int> res;

        for (auto& c : p) {
            us.insert(c);
            um[c]++;
        }

        for (int i = 0; i < p.size() - 1; i++) {
            if (us.count(s[i])) {
                um[s[i]]--;
                if (um[s[i]] >= 0)
                    rem--;
            }
        }

        for (int i = p.size() - 1; i < s.size(); i++) {
            if (us.count(s[i])) {
                um[s[i]]--;
                if (um[s[i]] >= 0)
                    rem--;
                if (rem == 0)
                    res.push_back(i - p.size() + 1);
            }

            int tail = i - p.size() + 1;
            if (us.count(s[tail])) {
                um[s[tail]]++;
                if (um[s[tail]] > 0) {
                    rem++;
                }
            }
        }

        return res;
    }
};

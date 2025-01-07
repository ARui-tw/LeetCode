/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/string-matching-in-an-array
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        string s = "";
        vector<string> res;

        sort(words.begin(), words.end(), []
            (const string& first, const string& second) {
                return first.size() > second.size();
            }
        );

        for (auto w : words) {
            if (s.find(w) == string::npos) {
                s += " ";
                s += w;
            } else {
                res.push_back(w);
            }
        }

        return res;
    }
};

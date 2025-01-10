/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/word-subsets
 * Runtime: 11 ms (91.32%)
 */

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> vum1(26, 0);
        vector<int> vum2(26, 0);
        vector<int> vum2_tmp(26, 0);
        vector<string> res;

        for (int i = 0; i < words2.size(); i++) {
            for (auto c : words2[i]) {
                vum2_tmp[c - 'a']++;
            }

            for (int j = 0; j < 26; j++) {
                vum2[j] = max(vum2_tmp[j], vum2[j]);
            }
            fill(vum2_tmp.begin(), vum2_tmp.end(), 0);

        }

        bool flag = false;

        for (int i = 0; i < words1.size(); i++) {
            flag = false;
            for (auto c : words1[i]) {
                vum1[c - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                if (vum2[j] > vum1[j]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) res.push_back(words1[i]);
            fill(vum1.begin(), vum1.end(), 0);
        }

        return res;
    }
};

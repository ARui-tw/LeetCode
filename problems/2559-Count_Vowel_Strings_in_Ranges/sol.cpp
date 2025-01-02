/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-vowel-strings-in-ranges
 * Runtime: 2 ms (91.64%)
 */

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> sums (words.size() + 1, 0);
        vector<int> res (queries.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            sums[i+1] = sums[i] + (isVowel(words[i][0]) && isVowel(words[i][words[i].size() - 1]));
        }
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0], b = queries[i][1];
            res[i] = sums[b+1] - sums[a];
        }

        return res;
    }
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

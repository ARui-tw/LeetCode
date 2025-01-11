/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/construct-k-palindrome-strings
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;

        vector<int> vec(26, 0);
        int counter = 0;

        for (char &c : s) {
            vec[c - 'a']++;
        }

        for (auto& v : vec) {
            if (v % 2 != 0) counter++;
        }

        return counter <= k;
    }
};

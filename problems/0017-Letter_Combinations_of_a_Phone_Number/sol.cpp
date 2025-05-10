/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/letter-combinations-of-a-phone-number
 * Runtime: 0 ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string arr[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (digits == "") return res;

        auto dfs = [&](this const auto& self, int pos, string str) {
            if (pos == digits.size()) {
                res.push_back(str);
                return;
            }

            string cur = arr[digits[pos] - '2'];
            pos++;
            for (auto& c : cur) {
                self(pos, str + c);
            }
        };

        dfs(0, "");

        return res;
    }
};

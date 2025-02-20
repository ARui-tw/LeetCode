/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/find-unique-binary-string
 * Runtime: 0 ms (100.00%)
 */

class Solution {
    vector<string> nums;
    string res = "";
    int n;
public:
    string findDifferentBinaryString(vector<string>& nums) {
        this->nums = nums;
        this->n = nums.size();

        dfs();

        return res;
    }

    bool dfs() {
        if (res.size() == n) {
            for (auto& n : nums) {
                if (n == res) {
                    return false;
                }
            }
            return true;
        }

        for (int i = 0; i <= 1; i++) {
            res += '0' + i;
            if (dfs()) return true;
            res.pop_back();
        }

        return false;
    }
};

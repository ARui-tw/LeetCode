/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/plus-one
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> res;
        res.reserve(n);
        bool add = true;
        for (int i = n - 1; i >= 0; i--) {
            if (add) {
                if (digits[i] == 9) {
                    add = true;
                    res.push_back(0);
                } else {
                    add = false;
                    res.push_back(digits[i] + 1);
                }
            } else {
                res.push_back(digits[i]);
            }
        }

        if (add) {
            res.push_back(1);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

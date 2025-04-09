/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k
 * Runtime: 7 ms (89.94%)
 */

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> us;

        for (auto& n : nums) {
            if (n < k) return -1;

            us.insert(n);
        }

        return us.count(k) ? us.size() - 1 : us.size();
    }
};

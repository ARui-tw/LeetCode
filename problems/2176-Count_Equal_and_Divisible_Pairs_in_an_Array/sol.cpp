/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array
 * Runtime: 0 ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) res++;
            }
        }

        return res;
    }
};

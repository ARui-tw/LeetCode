/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i
 * Runtime: 0 ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int one = 0, zero = 0, both = 0;
        bool prevOne = nums[0] & 1? false : true;
        for (auto n : nums) {
            bool isOne = n & 1;
            if (prevOne && !isOne) {
                both++;
                prevOne = false;
            } else if (!prevOne && isOne) {
                both++;
                prevOne = true;
            }

            if (isOne) {
                one++;
            } else {
                zero++;
            }
        }

        return max(one, max(zero, both));
    }
};

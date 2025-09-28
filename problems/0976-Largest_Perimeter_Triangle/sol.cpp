/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/largest-perimeter-triangle
 * Runtime: 4 ms (65.53%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] < nums[i + 1] + nums[i + 2]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }

        return 0;
    }
};

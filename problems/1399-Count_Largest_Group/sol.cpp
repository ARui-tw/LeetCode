/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-largest-group
 * Runtime: 0 ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> count;
        int ma = 0;
        int res = 0;

        for (int i = 1; i <= n; i++) {
            int sum = 0;
            int cur = i;
            while (cur) {
                sum += (cur % 10);
                cur /= 10;
            }

            ma = max(++count[sum], ma);
        }

        for (auto& c : count) {
            if (c.second == ma) ++res;
        }

        return res;
    }
};

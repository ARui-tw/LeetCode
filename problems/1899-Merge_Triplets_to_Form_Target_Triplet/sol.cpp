/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/merge-triplets-to-form-target-triplet
 * Runtime: 0 ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool count[] = {false, false, false};
        for (auto& t : triplets) {
            bool canUse = true;
            for (int i = 0; i < 3; i++) {
                if (target[i] < t[i]) {
                    canUse = false;
                    break;
                }
            }
            if (canUse) {
                for (int i = 0; i < 3; i++) {
                    if (target[i] == t[i]) {
                        count[i] = true;
                    }
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            if (count[i] == false)
                return false;
        }
        return true;
    }
};

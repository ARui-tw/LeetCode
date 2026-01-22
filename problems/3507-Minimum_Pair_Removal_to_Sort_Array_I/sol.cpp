/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int res = 0;
        int n = nums.size();

        while (!is_sorted(nums.begin(), nums.end())) {
            int mi = INT_MAX;
            int pos = -1;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i - 1] + nums[i] < mi) {
                    mi = nums[i - 1] + nums[i];
                    pos = i - 1;
                }
            }
            nums[pos] += nums[pos + 1];
            nums.erase(nums.begin() + pos + 1);
            res++;
        }

        return res;
    }
};

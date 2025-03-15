/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/house-robber-iv
 * Runtime: 16 ms (91.40%)
 */

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = 0, r = *max_element(nums.begin(), nums.end());
        int mid;
        int counter;

        while (l <= r) {
            mid = (l + r) / 2;

            counter = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) {
                    counter++;
                    i++;
                }
            }
            if (counter >= k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return r + 1;
    }
};

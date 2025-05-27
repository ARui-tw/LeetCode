/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (nums[mid] < nums[r]) r = mid;
            else l = mid + 1;
        }

        return nums[r];
    }
};

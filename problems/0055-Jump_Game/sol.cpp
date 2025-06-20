/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/jump-game
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        int cnt = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (cnt == -1 && nums[i] == 0) {
                cnt = 1;
                continue;
            }
            if (cnt != -1)  {
                cnt++;
                if (nums[i] < cnt) {
                    nums[i] = 0;
                } else {
                    cnt = 0;
                }
            } 
        }

        return nums[0] != 0;
    }
};

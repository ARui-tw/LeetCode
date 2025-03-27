/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/minimum-index-of-a-valid-split
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int domi = nums[0];
        int count = 0;
        int ma = 0;
        int n = nums.size();

        for (auto& n : nums) {
            if (n == domi) count++;
            else count--;
            if (count == 0) {
                domi = n;
                count = 1;
            }
        }

        for (auto& n : nums) if (n == domi) ma++;

        int leftDomi = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == domi) leftDomi++;

            if (leftDomi > ((i + 1) / 2) && (ma - leftDomi) > (n - i - 1) / 2) 
                return i; 
        }

        return -1;
    }
};

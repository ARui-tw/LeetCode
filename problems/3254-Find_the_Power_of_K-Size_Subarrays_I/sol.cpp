/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int l = 0;
        int prev;
        int r;
        for (r = 1; r < k; r++) {
            if (nums[r] - nums[r-1] != 1) l = r;
        }

        r--;
        if (r - l < k-1) ans.push_back(-1);
        else ans.push_back(nums[r]);


        for (int r = k; r < nums.size(); r++) {
            if (nums[r] - nums[r-1] != 1) l = r;

            if (r - l < k-1) ans.push_back(-1);
            else ans.push_back(nums[r]);
        }
        return ans;
    }
};


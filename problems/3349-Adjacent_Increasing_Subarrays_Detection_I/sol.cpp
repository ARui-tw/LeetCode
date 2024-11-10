/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i
 * Runtime: ms (%)
 */

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (k == 1) return true;
        int start = 0;
        int end = 0;
        vector<pair<int, int>> sub;
        for (int i = 1; i < nums.size(); i++) {
            int prev = nums[i - 1];
            if (prev < nums[i]) end++;
            else {
                if (end - start + 1 >= k*2) return true;
                if (end - start + 1 >= k) sub.push_back({start, end});
                start = end+1;
                end = end+1;
            }
        }
        if (end - start + 1 >= k) sub.push_back({start, end});
        if (end - start + 1 >= k*2) return true;


        if (sub.size() > 1)
            for (int i = 0; i < sub.size()-1; i++) {
                if (sub[i].second == sub[i+1].first - 1) return true;
            }
        return false;

    }
};

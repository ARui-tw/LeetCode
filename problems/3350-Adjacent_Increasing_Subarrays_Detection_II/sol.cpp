/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii
 * Runtime: ms (%)
 */

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int start = 0;
        int end = 0;
        int k = 1;
        vector<pair<int, int>> sub;
        for (int i = 1; i < nums.size(); i++) {
            int prev = nums[i - 1];
            if (prev < nums[i])
                end++;
            else {
                sub.push_back({start, end});
                if ((end - start + 1) / 2 > k) k = (end - start + 1) / 2;
                start = end + 1;
                end = end + 1;
            }
        }

        sub.push_back({start, end});
        if ((end - start + 1) / 2 > k) k = (end - start + 1) / 2;

        if (sub.size() > 1)
            for (int i = 0; i < sub.size() - 1; i++) {
                if (sub[i].second == sub[i + 1].first - 1) {
                    int tmp = min(sub[i].second - sub[i].first + 1,
                            sub[i+1].second - sub[i+1].first + 1);
                    if (tmp > k) {
                        k = tmp;
                    }
                }
            }
        return k;
    }
};

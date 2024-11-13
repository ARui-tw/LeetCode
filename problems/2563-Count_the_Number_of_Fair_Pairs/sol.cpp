/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-the-number-of-fair-pairs
 * Runtime: 23ms (98.81%)
 */

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        long long count = 0;
        int low = n - 1, up = n - 1;

        for (int k = 0; k < nums.size(); k++) {
            int i = nums[k];
            while (k < low && low >= 0 && i + nums[low] >= lower) {
                low--;
            }

            while(up >= 0 && i + nums[up] > upper) {
                up--;
            }

            if (up < k) break;
            if (up > low) {
                if (k < low) {
                    count += up - low;
                } else {
                    count += up - k;
                }
            }

        }

        return count;
    }
};


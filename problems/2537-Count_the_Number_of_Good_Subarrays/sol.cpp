/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-the-number-of-good-subarrays
 * Runtime: 77 ms (75.12%)
 */

class Soution {
public:
    long long countGood(vector<int>& nums, int k) {
        int l = 0, r = 0, lastL = -1;
        int n = nums.size();
        long long sets = 0;
        unordered_map<int, int> um;
        um[nums[l]]++;
        long long res = 0;

        while (r < n) {
            if (sets >= k) {
                res += (l - lastL) * (n - r);
                lastL = l;
                um[nums[l]]--;
                sets -= um[nums[l]];
                l++;
            } else {
                r++;
                if (r == n) break;
                sets += um.count(nums[r]) > 0 ? um[nums[r]] : 0;
                um[nums[r]]++;
            }
        }

        return res;
    }
};

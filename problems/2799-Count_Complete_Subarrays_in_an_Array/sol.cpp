/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-complete-subarrays-in-an-array
 * Runtime: 19 ms (67.47%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = -1;
        int total;
        int count = 0;
        int res = 0;
        unordered_set<int> us;
        unordered_map<int, int> um;

        for (auto &num : nums) {
            us.insert(num);
        }

        total = us.size();

        while (l < n) {
            while (count != total && r + 1 < n) {
                r++;
                if (++um[nums[r]] == 1)
                    count++;
            }

            if (r + 1 == n && count != total) break;

            res += (n - r);
            
            // printf("%d, %d: %d\n", l, r, (n-r));

            if (--um[nums[l]] == 0)
                count--;

            l++;
        }

        return res;
    }
};

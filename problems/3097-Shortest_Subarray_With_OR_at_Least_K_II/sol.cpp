/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii
 * Runtime: 66ms (54.95%)
 */

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> a;
        int l = 0;
        int ans = nums.size() + 1;
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            int j = 0;
            while (cur) {
                if (a.size() < j + 1) {
                    a.push_back(0);
                }
                a[j] += cur % 2;
                cur /= 2;
                j++;
            }
            int sum = 0;
            for (int i = 0; i < a.size(); i++)
                if (a[i] > 0) sum += pow(2, i);
            if (sum >= k && ans > i - l + 1) ans = i - l + 1;

            while (sum >= k && l < i) {
                int sub = nums[l];
                j = 0;
                while (sub) {
                    if (a.size() < j + 1)
                        a.push_back(0);
                    a[j] -= sub % 2;
                    sub /= 2;
                    j++;
                }

                sum = 0;
                for (int i = 0; i < a.size(); i++)
                    if (a[i] > 0) sum += pow(2, i);

                l++;
                if (sum >= k && ans > i - l + 1) ans = i - l + 1;
            }
        }

        if (ans == nums.size() + 1) return -1;
        return ans;
    }
};

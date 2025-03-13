/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/zero-array-transformation-ii
 * Runtime: 14 ms (73.46%)
 */

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int qn = queries.size();
        int n = nums.size();
        int l = 0, r = qn - 1;
        int mid;
        int prevMid = -1;
        int sum;
        bool success;
        vector<int> diffArr(nums.size() + 1, 0);

        success = true;
        for (auto num : nums) {
            if (num > 0) {
                success = false;
                break;
            }
        }
        if (success) return 0;

        while (l <= r) {
            mid = (l + r) / 2;
            if (mid > prevMid) {
                for (int i = prevMid + 1; i <= mid; i++) {
                    diffArr[queries[i][0]] += queries[i][2];
                    diffArr[queries[i][1] + 1] -= queries[i][2];
                }
            } else {
                for (int i = prevMid; i > mid; i--) {
                    diffArr[queries[i][0]] -= queries[i][2];
                    diffArr[queries[i][1] + 1] += queries[i][2];
                }
            }

            prevMid = mid;

            success = true;
            sum = 0;
            for (int i = 0; i < n; i++) {
                sum += diffArr[i];
                if (nums[i] > sum) {
                    success = false;
                    break;
                }
            }

            if (success) {
                // printf("%d success\n", mid);
                r = mid - 1;
            } else {
                // printf("%d fail\n", mid);
                l = mid + 1;
            }
        }

        // printf("%d, %d\n", l, r);
        if (r == qn - 1 && !success) return -1;

        return r + 2;
    }
};

// [0, 0, 0]
// [1, 0, 0, -1]
// [2, 0, 0, -2]
// [2, 3, -3, -2]

// 2, 5, 2

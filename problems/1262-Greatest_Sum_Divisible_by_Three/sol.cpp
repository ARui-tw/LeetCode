/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/greatest-sum-divisible-by-three
 * Runtime: 28 ms (54.37%)
 */

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        dp[0][0] = 0;
        dp[0][1] = INT_MIN;
        dp[0][2] = INT_MIN;

        for (int i = 1; i <= n; i++) {
            int cur = nums[i - 1];
            int curRem = cur % 3;
            if (curRem == 0) {
                dp[i][0] = dp[i - 1][0] + cur;
                dp[i][1] = dp[i - 1][1] + cur;
                dp[i][2] = dp[i - 1][2] + cur;
            } else if (curRem == 1) {
                dp[i][0] = max(dp[i-1][2] + cur, dp[i-1][0]);
                dp[i][1] = max(dp[i-1][0] + cur, dp[i-1][1]);
                dp[i][2] = max(dp[i-1][1] + cur, dp[i-1][2]);
            } else {
                dp[i][0] = max(dp[i-1][1] + cur, dp[i-1][0]);
                dp[i][1] = max(dp[i-1][2] + cur, dp[i-1][1]);
                dp[i][2] = max(dp[i-1][0] + cur, dp[i-1][2]);
            }
        }

        return dp[n][0];
    }
};

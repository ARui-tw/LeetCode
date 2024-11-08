/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-xor-for-each-query
 * Runtime: ms (%)
 */

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int k = pow(2, maximumBit) - 1;
        int a = k;
        for (int i = 0; i < nums.size(); i++) {
            a ^= nums[i];
            ans.push_back(a);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
}

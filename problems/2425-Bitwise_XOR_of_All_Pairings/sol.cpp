/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/bitwise-xor-of-all-pairings
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        if (nums1.size() & 1) {
            for (int &n : nums2) {
                ans ^= n;
            }
        }

        if (nums2.size() & 1) {
            for (int &n : nums1) {
                ans ^= n;
            }
        }
        
        return ans;
    }
};

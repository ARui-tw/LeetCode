/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        res.reserve(nums.size());

        for (auto& n : nums) {
            if (n == 2) {
                res.push_back(-1);
                continue;
            }
            
            bitset<31> bs = n;
            for (int i = 1; i < 31; i++) {
                if (bs[i] == 0) {
                    bs[i-1] = 0;
                    break;
                }
            }
            res.push_back(bs.to_ulong());
        }

        return res;
    }
};

// 11 -> 1 or 10
// 101 -> 100 or 101
// 111 -> 11 or 100

// 1011 -> 1001 or 1010
// 1101 -> 1100

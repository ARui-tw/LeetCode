/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/apply-operations-to-an-array
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int counter = 0;
        int i;

        for (i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                if (nums[i] == 0) {
                    i++;
                } else {
                    res[counter++] = nums[i++] * 2;
                }
            } else {
                if (nums[i] != 0) {
                    res[counter++] = nums[i];
                }
            }
        }

        if (i == nums.size() - 1) {
            res[counter] = nums[i];
        }

        return res; 
    }
};

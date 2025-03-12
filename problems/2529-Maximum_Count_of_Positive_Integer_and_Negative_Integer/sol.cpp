/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int mid;
        int negCount;
        int posCount;
        if (nums[l] >= 0) negCount = 0;
        else 
            while (r - l > 1) {
                mid = (l + r) / 2;
                if (nums[mid] >= 0) r = mid;
                else l = mid;
            }

            if (nums[l] >= 0) negCount = 0;
            else if (nums[r] < 0) negCount = n;
            else negCount = l + 1;

        l = 0, r = nums.size() - 1;
        if (nums[r] <= 0) posCount = r + 1;
        else 
            while (r - l > 1) {
                mid = (l + r) / 2;
                if (nums[mid] <= 0) l = mid;
                else r = mid;
            }


            if (nums[r] <= 0) posCount = 0;
            else if (nums[l] > 0) posCount = n;
            else posCount = n - r;
        
        return max(posCount, negCount);
    }
};

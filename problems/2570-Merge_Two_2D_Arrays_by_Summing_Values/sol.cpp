/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int p1 = 0, p2 = 0;
        int id1, id2, n1, n2;
        vector<vector<int>> res;

        while (p1 < n && p2 < m) {
            id1 = nums1[p1][0];
            id2 = nums2[p2][0];
            n1 = nums1[p1][1];
            n2 = nums2[p2][1];

            if (id1 == id2) {
                res.push_back({id1, n1 + n2});
                p1++;
                p2++;
            } else if (id1 < id2) {
                res.push_back({id1, n1});
                p1++;
            } else {
                res.push_back({id2, n2});
                p2++;
            } 
        }

        while (p1 < n) {
            id1 = nums1[p1][0];
            n1 = nums1[p1][1];
            res.push_back({id1, n1});
            p1++;
        }

        while (p2 < m) {
            id2 = nums2[p2][0];
            n2 = nums2[p2][1];
            res.push_back({id2, n2});
            p2++;
        }

        return res;
    }
};

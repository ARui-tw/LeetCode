/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> rec(A.size() + 1, -2);
        vector<int> res(A.size(), 0);
        int counter = 0;
        int a, b;

        for (int i = 0; i < A.size(); i++) {
            if (++rec[A[i]] == 0) counter++;

            if (++rec[B[i]] == 0) counter++;

            res[i] = counter;
        }

        return res;
    }
};

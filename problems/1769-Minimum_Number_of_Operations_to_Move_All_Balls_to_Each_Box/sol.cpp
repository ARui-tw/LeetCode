/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int right = 0, left = 0;
        int n = boxes.size();
        vector<int> res(n, 0);

        for (int i = 1; i < n; i++) {
            char c = boxes[i];

            if (c == '1') {
                res[0] += i;
                right++;
            }
        }

        if (boxes[0] == '1') left++;

        for (int i = 1; i < n; i++) {
            res[i] = res[i-1] + (left - right);
            if (boxes[i] == '1') right--;
            if (boxes[i] == '1') left++;
        }
        
        return res;
    }
};

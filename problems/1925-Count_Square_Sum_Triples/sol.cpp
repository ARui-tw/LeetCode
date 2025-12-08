/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-square-sum-triples
 * Runtime: 3 ms (90.49%)
 */

class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                double target = sqrt(i * i + j * j);
                if (target > n) break;
                if (floor(target) == target)
                    res += i == j ? 1 : 2;
            }
        }

        return res;
    }
};

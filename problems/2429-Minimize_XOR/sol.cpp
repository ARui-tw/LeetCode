/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/minimize-xor
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n = 0;
        int res = 0;
        stack<int> sta;
        int ones = 0;
        int zeros = 0;

        while (num2 > 0) {
            n += num2 % 2;
            num2 /= 2;
        }
  
        while (num1 > 0) {
            if (num1 % 2) {
                ones++;
                sta.push(0);
            } else {
                zeros++;
                sta.push(zeros);
            }
            num1 /= 2;
        }
 
        while (n - (ones + zeros) > 0) {
            if (res == 0) res = 1;
            else {
                res <<= 1;
                res |= 1;
            }
            n--;
        }

        while (!sta.empty()) {
            int cur = sta.top();
            res <<= 1;

            if (!cur && n > 0) {
                n--;
                ones--;
                res |= 1;
            } else if (cur && cur <= (n - ones)) {
                n--;
                res |= 1;
            }
            sta.pop();
        }

        return res;
    }
};

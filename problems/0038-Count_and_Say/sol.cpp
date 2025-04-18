/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-and-say
 * Runtime: 3 ms (83.88%)
 */

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        return encode(countAndSay(n - 1));
    }

    string encode(string s) {
        string res = "";
        char prev = 'n';
        int count = 0;
        for (auto c : s) {
            // printf("%c\n", c);
            if (c != prev) {
                if (count > 0) {
                    res += ('0' + count);
                    res += prev;
                }
                count = 1;
                prev = c;
            } else count++;
        }
        // printf("\n");

        if (count > 0) {
            res += ('0' + count);
            res += prev;
        }

        return res;
    }
};

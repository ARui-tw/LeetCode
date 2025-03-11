/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters
 * Runtime: 1 ms (94.32%)
 */

class Solution {
public:
    int numberOfSubstrings(string s) {
        int tail = 0;
        int res = 0;
        int n = s.size();
        int chars[] = {0, 0, 0};
        int req = 3;

        for (int i = 0; i < n; i++) {
            if (chars[s[i] - 'a']++ == 0) {
                req--;
            }

            while (req == 0) {
                res += n - i;
                // printf("res: %d\n", res);

                if (--chars[s[tail] - 'a'] == 0) {
                    req++;
                }
                tail++;
            }
        }

        return res;
    }
};

/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-collisions-on-a-road
 * Runtime: 7 ms (82.03%)
 */

class Solution {
public:
    int countCollisions(string directions) {
        int cnt = 0;
        int res = 0;
        bool prevStop = false;

        for (auto& d : directions) {
            if (d == 'S') {
                prevStop = true;
                res += cnt;
                cnt = 0;
            } else if (d == 'R') {
                cnt++;
                prevStop = false;
            } else {
                if (cnt > 0) {
                    res += cnt + 1;
                    cnt = 0;
                    prevStop = true;
                } else if (prevStop) {
                    res++;
                }
            }
        }

        return res;
    }
};

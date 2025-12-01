/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-running-time-of-n-computers
 * Runtime: 12 ms (97.13%)
 */

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long r = 0, sum = 0;

        r = reduce(batteries.begin(), batteries.end(), 0LL) / n;

        auto valid = [&](long long time) -> bool {
            long long reserve=0;
            for (auto& b : batteries) {
                reserve += min((long long)b, time);
            }
            return reserve >= time * n;
        };

        long long l = 0;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (valid(mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return l - 1;
    }
};

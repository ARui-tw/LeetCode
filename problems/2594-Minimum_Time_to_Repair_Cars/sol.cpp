/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/minimum-time-to-repair-cars
 * Runtime: 52 ms (54.24%)
 */

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0, r = (long long)*min_element(ranks.begin(), ranks.end()) * cars * cars;
        long long mid, sum;
        while (l <= r) {
            mid = (l + r) / 2;

            sum = 0;
            for (auto &r : ranks) {
                sum += sqrt(mid / r);
            }
            if (sum >= cars) r = mid - 1;
            else l = mid + 1;
        }

        return r + 1;
        
    }
};

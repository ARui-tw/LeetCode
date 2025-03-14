/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-candies-allocated-to-k-children
 * Runtime: 21 ms (79.73%)
 */

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1, r = *max_element(candies.begin(), candies.end());
        int mid;

        auto valid = [&](int pile) -> bool {
            long long sum = 0;
            for (auto& c : candies) {
                sum += c / pile;
            }

            return sum >= k;
        };

        while (l <= r) {
            mid = (r + l) / 2;

            if (valid(mid)) l = mid + 1;
            else r = mid - 1;
        }

        return l - 1;
    }
};

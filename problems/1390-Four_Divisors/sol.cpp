/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/four-divisors
 * Runtime: 16 ms (65.27%)
 */

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        unordered_map<int, int> um;
        int res = 0;
        auto cal = [&](int num) -> int {
            if (um.count(num)) return um[num];
            int find = 0;
            int sum = 1 + num;
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    find++;
                    sum += i;
                    if (i * i != num) {
                        find++;
                        sum += num / i;
                    }
                }
                if (find > 2) {
                    return um[num] = 0;
                }
            }

            if (find != 2) return um[num] = 0;
            return um[num] = sum;
        };

        for (auto& num : nums) {
            res += cal(num);
        }

        return res;
    }
};

/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/closest-prime-numbers-in-range
 * Runtime: 149 ms (73.70%)
 */

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        vector<int> ans(2, -1);
        int lastPrime = -1;
        int minDist = INT_MAX;

        isPrime[1] = false;

        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {

                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                if (lastPrime != -1) {
                    if (i - lastPrime < minDist) {
                        ans[0] = lastPrime;
                        ans[1] = i;
                        minDist = i - lastPrime;
                        if (minDist <= 2) return ans;
                    }
                }
                lastPrime = i;
            }
        }

        // return {-1, -1};
        return ans;
    }
};

// 2 3 5 7 11 13 17 19

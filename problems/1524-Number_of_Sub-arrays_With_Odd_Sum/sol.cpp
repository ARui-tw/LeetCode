/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum
 * Runtime: 12 ms (23.62%)
 */

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        queue<bool> que;
        long long sum = 0;
        long long evenSum = 0;
        long long oddSum = 0;
        long long res = 0;
        int mod = 1000000007;
        long long tmp;
        bool reverse = false;

        for (auto& a : arr) {
            sum += a;
            que.push(sum & 1);
            if (sum & 1) oddSum++;
            else evenSum++;
        }

        int counter = 0;
        while (!que.empty()) {
            res = (res + oddSum) % mod;

            bool top = que.front();

            if (top) 
                if (reverse) evenSum--;
                else oddSum--;
            else 
                if (reverse) oddSum--;
                else evenSum--;

            que.pop();

            if (arr[counter] & 1) {
                tmp = evenSum;
                evenSum = oddSum;
                oddSum = tmp;
                reverse = !reverse;
            }

            counter++;
        }

        // res = res % mod;
        return res;
    }
};

// 1 2 3 4 5 6 7
//  1 = 1
//  3 = 1 2
//  6 = 1 2 3
// 10 = 1 2 3 4
// 15 = 1 2 3 4 5
// 21 = 1 2 3 4 5 6
// 28 = 1 2 3 4 5 6 7

// 4 3 
// 3 3

// 4 + 3 + 3

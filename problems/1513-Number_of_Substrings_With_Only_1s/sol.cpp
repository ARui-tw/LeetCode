/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/number-of-substrings-with-only-1s
 * Runtime: 2 ms (39.33%)
 */

class Solution {
    int mod = 1e9 + 7;
public:
    int numSub(string s) {
        int l = -1;
        int n = s.size();
        vector<int> cnt(n + 1, 0);
        long long res = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '1' && s[i + 1] == '0') { // found right bound
                cnt[i - l]++;
            } else if (s[i] == '0' && s[i + 1] == '1') {
                l = i;
            }
        }

        if (s[n - 1] == '1') {
            cnt[n - 1 - l]++;
        }

        for (long long i = 1; i < cnt.size(); i++) {
            if (cnt[i] != 0)
                res += ((i + 1) * i / 2 * cnt[i]) % mod;
            res %= mod;
        }

        return res;
    }
};

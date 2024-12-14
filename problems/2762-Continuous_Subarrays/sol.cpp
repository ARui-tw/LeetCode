/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/continuous-subarrays
 * Runtime: 94ms (79.04%)
 */
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        long long mi = INT_MAX;
        long long ma = INT_MIN;
        long long re = 0;
        long long counter = 0;
        bool flag_min = false;
        bool flag_max = false;
        vector<long long> record;
        vector<long long> vs;
        long long prev;
        for (auto n : nums) {
            re = 0;
            counter = 0;
            flag_min = false;
            flag_max = false;
            ans++;
            re++;
            mi = n;
            ma = n;
            for (int i = vs.size() - 1; i >= 0; i--) {
                counter++;
                if (!flag_min && mi >= vs[i]) {
                    flag_min = true;
                }
                if (!flag_max && mi >= vs[i]) {
                    prev = record[i];
                    counter=0;
                }
                if (!flag_max && ma <= vs[i]) {
                    flag_max = true;
                }
                if (!flag_min && ma <= vs[i]) {
                    prev = record[i];
                    counter=0;
                }
                if (flag_min && flag_max) {
                    ans += prev - counter;
                    re += prev - counter;
                    break;
                }
                mi = min(mi, vs[i]);
                ma = max(ma, vs[i]);
                if ((ma - mi) <= 2) {
                    re++;
                    ans++;
                }
                else break;
            }
            vs.push_back(n);
            record.push_back(re);
        }

        return ans;
    }
};

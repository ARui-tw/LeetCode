/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/largest-divisible-subset
 * Runtime: 9 ms (79.63%)
 */

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, 1);
        vector<int> nxt(n, -1);
        vector<int> ans;

        sort(nums.begin(), nums.end());

        int ma = nums[n - 1];
        int ansLen = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] % nums[i] != 0) continue;
                if (v[i] < v[j] + 1) {
                    v[i] = 1 + v[j];
                    nxt[i] = j;
                    ansLen = max(v[i], ansLen);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (v[i] == ansLen) {
                int cur = i;
                while (cur != -1) {
                    ans.push_back(nums[cur]);
                    cur = nxt[cur];
                }

                return ans;
            }
        }

        return ans;
    }
};


// 1 6 12 36
// 3 4 6 8 12 36
// 3 12 36
// 4 8 36
// 4 12 36

/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field
 * Runtime: 945 ms (88.35%)
 */

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        unordered_set<int> seen;
        int ma = -1;
        long long mod = 1e9 + 7;

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                seen.insert(hFences[j] - hFences[i]);
            }
        }

        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                if (seen.count(vFences[j] - vFences[i])) 
                    ma = max(ma, vFences[j] - vFences[i]);
            }
        }
        
        return ma == -1 ? ma : (ma % mod) * (ma % mod) % mod;
    }
};

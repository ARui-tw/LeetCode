/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/time-based-key-value-store-981.-time-based-key-value-store
 * Runtime: 59 ms (33.49%)
 */

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dist(26, vector<long long>(26, 1e15));
        long long res = 0;

        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }

        for (int i = 0; i < original.size(); i++) {
            dist[original[i] - 'a'][changed[i] - 'a'] = min((long long)cost[i], dist[original[i] - 'a'][changed[i] - 'a']);
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }

        for (int i = 0; i < source.size(); i++) {
            if (dist[source[i] - 'a'][target[i] - 'a'] != 1e15) {
                res += dist[source[i] - 'a'][target[i] - 'a'];
            } else return -1;
        }

        return res;
    }
};

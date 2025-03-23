/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination
 * Runtime: 59 ms (5.29%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
    long long res;
    long long mod;
    long long curMin;
    vector<vector<pair<int, long long>>> graph;
    vector<long long> shortest;
    vector<long long> mem;

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        res = 0;
        mod = 1e9 + 7;
        curMin = LONG_LONG_MAX;
        graph.resize(n, vector<pair<int, long long>>());
        shortest.resize(n, -1);
        mem.resize(n, -1);

        for (auto& road : roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        shortest[0] = 0;
        dfs(0, 0, n);

        return dp(n - 1, 0, n);
    }

    long long dp(int cur, long long time, int n) {
        if (mem[cur] != -1) return mem[cur];

        long long total = 0;
        if (cur == 0) {
            return 1;
        }

        for (auto& nei : graph[cur]) {
            if (shortest[nei.first] + time + nei.second == curMin) {
                total += dp(nei.first, time + nei.second, n) % mod;
            }
        }

        mem[cur] = total % mod;

        return mem[cur];
    }

    void dfs(int cur, long long time, int n) {
        if (cur == n - 1) {
            if (time < curMin) {
                res = 1;
                curMin = time;
            } else if (time == curMin) {
                res = ++res % mod;
            }

            return;
        }

        for (auto& nei : graph[cur]) {
            if (shortest[nei.first] == -1 ||
                shortest[nei.first] > time + nei.second) {
                shortest[nei.first] = nei.second + time;
                dfs(nei.first, time + nei.second, n);
            }
        }
        return;
    }
};

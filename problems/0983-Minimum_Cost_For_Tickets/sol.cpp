/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/minimum-cost-for-tickets
 * Runtime: 0 ms (100.00%)
 */

class Solution {
    vector<int> days;
    vector<int> costs;
    vector<int> mem;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->days = days;
        this->costs = costs;
        mem.resize(days.size(), -1);

        return sol(0);
    }
    int sol(int cur) {
        if (mem[cur] != -1) return mem[cur];
        int curDay = days[cur];
        int onePrice = 0, sevenPrice = 0, thirtyPrice = 0;
        for (int i = cur; i < days.size(); i++) {
            if (!onePrice && days[i] >= curDay + 1) {
                onePrice = sol(i);
            }
            if (!sevenPrice && days[i] >= curDay + 7) {
                sevenPrice = sol(i);
            }
            if (!thirtyPrice && days[i] >= curDay + 30) {
                thirtyPrice = sol(i);
                break;
            }
        }

        int sol = min(onePrice + costs[0], min(sevenPrice + costs[1], thirtyPrice + costs[2]));

        mem[cur] = sol;
        return sol;
    }
};

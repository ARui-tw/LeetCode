/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-matching-of-players-with-trainers
 * Runtime: 23 ms (95.97%)
 */

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int res = 0;
        for (int i = 0, j = 0; i < players.size() && j < trainers.size(); i++) {
            while (j < trainers.size() && trainers[j] < players[i]) {
                j++;
            }
            if (j < trainers.size()) res++;
            j++;
        }

        return res;
    }
};

/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-mentions-per-user
 * Runtime: 33 ms (58.16%)
 */

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = numberOfUsers;
        vector<int> res(n, 0);
        vector<int> online(n, 0);

        sort(events.begin(), events.end(), [](const vector<string>& lhs, const vector<string>& rhs) {
            return lhs[1] != rhs[1] ? atoi(lhs[1].c_str()) < atoi(rhs[1].c_str()) : lhs[0] == "OFFLINE";
        });

        for (auto &event : events) {
            if (event[0] == "MESSAGE") {
                if (event[2] == "ALL") {
                    for (int i = 0; i < n; i++) {
                        res[i]++;
                    }
                } else if (event[2] == "HERE") {
                    for (int i = 0; i < n; i++) {
                        if (online[i] <= atoi(event[1].c_str())) {
                            res[i]++;
                        }
                    }
                } else {
                    size_t pos = 0;
                    string token;
                    while ((pos = event[2].find(" id")) != string::npos) {
                        token = event[2].substr(2, pos);
                        res[atoi(token.c_str())]++;
                        event[2].erase(0, pos + 1);
                    }
                    res[atoi(event[2].substr(2).c_str())]++;
                }
            } else {
                online[atoi(event[2].c_str())] = atoi(event[1].c_str()) + 60;
            }
        }

        return res;
    }
};

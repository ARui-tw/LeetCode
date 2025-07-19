/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem
 * Runtime: 39 ms (94.62%)
 */

class Solution {
    typedef struct folder {
        string name;
        vector<struct folder*> childs;
        bool last;
    } folder_t;
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        sort(folder.begin(), folder.end(), [](const string &lhs, const string &rhs) {
            return lhs.size() < rhs.size();
        });
        unordered_set<string> us;
        for (auto& s : folder) {
            bool found = false;
            string path = "/";
            for (int i = 1; i < s.size(); i++) {
                while (i < s.size() && s[i] != '/') {
                    path += s[i];
                    i++;
                }
                if (us.count(path)) {
                    found = true;
                    break;
                }
                path += '/';
            }
            if (!found) {
                us.insert(s);
                res.push_back(s);
            }
        }
        return res;
    }
};

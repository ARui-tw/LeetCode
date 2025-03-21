/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies
 * Runtime: 207 ms (35.02%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        queue<string> qu;
        vector<unordered_set<string>> vus(n, unordered_set<string>());
        vector<string> res;

        for (auto &s : supplies) {
            qu.push(s);
        }

        for (int i = 0; i < n; i++) {
            for (auto &ingre : ingredients[i])
                vus[i].insert(ingre);
        }

        while (!qu.empty()) {
            auto top = qu.front();
            qu.pop();

            for (int i = 0; i < n; i++) {
                if (vus[i].size() > 0) {
                    vus[i].erase(top);
                    if (vus[i].size() == 0) {
                        res.push_back(recipes[i]);
                        qu.push(recipes[i]);
                    }
                }
            }
        }

        return res;
    }
};

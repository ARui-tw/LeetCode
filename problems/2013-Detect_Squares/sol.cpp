/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/detect-squares
 * Runtime: 35 ms (66.40%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class DetectSquares {
    unordered_map<int, unordered_map<int, int>> um;
public:
    DetectSquares() {}
    
    void add(vector<int> point) {
        um[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        int res = 0;
        for (auto& [y2, cnt] : um[x1]) {
            int side = y2 - y1;
            if (!side) continue;

            int x2 = x1 - side;
            int x3 = x1 + side;

            res += um[x2][y1] * um[x2][y2] * cnt;
            res += um[x3][y1] * um[x3][y2] * cnt;
        }

        return res;
    }
};

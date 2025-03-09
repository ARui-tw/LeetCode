/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/alternating-groups-ii
 * Runtime: 41 ms (99.58%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        bool init = true;
        int head = 0, tail = 0;
        int size = 1;
        int res = 0;

        while (tail == 0) {
            int prevHeadColor = colors[head];
            head = (head + 1) % n;

            if (colors[head] == prevHeadColor) {
                tail = head;
                size = 1;
                continue;
            }

            size++;
            if (size == k) {
                tail = (tail + 1) % n;
                size--;
                res++;
            }
        }

        while (tail < n || head < n) {
            int prevHeadColor = colors[head % n];
            head++;

            if (colors[head % n] == prevHeadColor) {
                tail = head;
                size = 1;
                continue;
            }

            size++;
            if (size == k) {
                tail++;
                size--;
                res++;
            }
        }

        return res;
    }
};

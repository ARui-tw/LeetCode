/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n
 * Runtime: 0 ms (100.00%)
 */

class Solution {
    int counter;
    string cur;
    int n, k;
public:
    string getHappyString(int n, int k) {
        counter = 0;
        cur = "";
        this->n = n;
        this->k = k;

        dfs();

        return cur;
    }

    void dfs() {
        if (cur.size() == n) {
            counter++;
            return;
        }

        for (int i = 0; i < 3; i++) {
            if (cur.size() == 0 || (cur.size() > 0 && cur.back() != 'a' + i)) {
                cur += 'a' + i;
                dfs();
                if (counter == k) return;
                cur.pop_back();
            }
        }
    }
};

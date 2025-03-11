/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/word-search
 * Runtime: 251 ms (67.30%)
 */

class Solution {
    const int stepX[4] = {0, 1, -1, 0};
    const int stepY[4] = {1, 0, 0, -1};
    int n, m;
    vector<vector<bool>> seen;
    vector<vector<char>> board;
    string word;
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->n = board.size();
        this->m = board[0].size();
        this->board = board;
        this->word = word;

        seen.resize(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                seen[i][j] = true;
                if (dfs(i, j, 0)) return true;
                seen[i][j] = false;
            }
        }

        return false;
    }
    bool dfs(int x, int y, int pos) {
        // cout << pos << endl;
        if (board[x][y] == word[pos]) {
            if (pos + 1 == word.size()) return true;
            for (int i = 0; i < 4; i++) {
                int nx = x + stepX[i];
                int ny = y + stepY[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !seen[nx][ny]) {
                    seen[nx][ny] = true;
                    if (dfs(nx, ny, pos + 1)) return true;
                    seen[nx][ny] = false;
                }
            }
        }
        return false;
    }
};

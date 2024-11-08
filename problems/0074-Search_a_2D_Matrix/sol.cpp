/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/search-a-2d-matrix/description/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = 0;
        int max_i = matrix.size() - 1;
        int max_j = matrix[0].size() - 1;

        while(true) {
            if (target == matrix[i][j]) return true;

            if (i < max_i && target >= matrix[i+1][j]) i++;
            else if (j < max_j && target >= matrix[i][j+1]) j++;
            else return false;
        }

        return false;
    }
};


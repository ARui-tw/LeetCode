/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-good-triplets
 * Runtime: 10 ms (36.18%)
 */

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int res = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (abs(arr[i] - arr[j]) <= a &&
                        abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                        res++;
                }
            }
        }

        return res;
    }
};

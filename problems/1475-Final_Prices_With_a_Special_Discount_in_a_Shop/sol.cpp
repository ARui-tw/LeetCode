/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        int j;
        
        for (int i = 0; i < n; i++) {
            j = i + 1; 
            while(j < n && prices[j] > prices[i]) j++;
            if (j != n) prices[i] -= prices[j];
        }

        return prices;
    }
};

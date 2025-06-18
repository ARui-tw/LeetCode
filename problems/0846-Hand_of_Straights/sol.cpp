/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/hand-of-straights
 * Runtime: 8 ms (95.64%)
 */

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (groupSize == 1) return true;
        if (n % groupSize != 0) return false;

        vector<int> need;
        int prev = -1;
        sort(hand.begin(), hand.end());
        queue<int> qu;
        int cur;
        int i = 0;
        
        while (i < n) {
            cur = hand[i];
            while (!qu.empty() && i < n && qu.front() == hand[i]) {
                qu.pop();
                i++;
            }
            if (!qu.empty() && cur != prev + 1) return false;
            if (!qu.empty() && qu.front() < cur) return false;
            
            int qs = qu.size();
            while (qs--) {
                if (i < n && hand[i] == cur) i++;
                else return false;
            }
            while (i < n && hand[i] == cur) {
                qu.push(cur + groupSize - 1);
                i++;
            }
            prev = cur;
        }

        return qu.empty();
    }
};

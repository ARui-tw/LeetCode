/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements
 * Runtime: 119 ms (87.16%)
 */

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> vec(n);
        vector<int> ans(n);
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++) {
            vec[i] = {nums[i], i};
        }

        sort(vec.begin(), vec.end());

        // for (auto v : vec) {
        //     printf("%d, %d\n", v.first, v.second);
        // }

        int first = 0;
        pq.push(vec[first].second);
        for (int i = 1; i < n; i++) {
            if (vec[i].first - vec[i-1].first > limit) {
                for (; first < i; first++) {
                    int top = pq.top();
                    pq.pop();
                    ans[top] = vec[first].first;
                    // printf("put %d at %d\n", vec[first].first, top);
                }
            } 

            pq.push(vec[i].second);
        }

        for (; first < n; first++) {
            int top = pq.top();
            pq.pop();
            ans[top] = vec[first].first;
            // printf("last: put %d at %d\n", vec[first].first, top);
        }

        return ans;
    }
};

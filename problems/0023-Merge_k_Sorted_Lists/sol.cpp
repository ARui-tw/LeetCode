/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/merge-k-sorted-lists
 * Runtime: 2 ms (70.41%)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* cur = new ListNode();
        ListNode* dummyHead = cur;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        int k = lists.size();

        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL)
                pq.push({lists[i]->val, lists[i]});
        }

        while (!pq.empty()) {
            auto [num, node] = pq.top();
            pq.pop();
            cur->next = node;
            if (node->next) {
                pq.push({node->next->val, node->next});
            }
            cur = cur->next;
        }

        return dummyHead->next;
    }
};

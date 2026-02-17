/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/merge-k-sorted-lists
 * Runtime: 0 ms (100.00%)
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
        priority_queue<ListNode*, vector<ListNode*>, decltype([](const ListNode* lhs, const ListNode* rhs) {
            return lhs->val > rhs->val;
        })> pq;
        ListNode dummy = ListNode();
        ListNode* cur = &dummy;

        for (auto& list : lists) {
            if (list) pq.push(list);
        }

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            cur->next = top;
            cur = top;
            if (top->next) pq.push(top->next);
        }

        return dummy.next;
    }
};

/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/reverse-nodes-in-k-group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        
        auto cur = head;
        int n = 0;
        while (cur) {
            n++;
            cur = cur->next;
        }

        int c = n / k;
        ListNode* prev = NULL, *res = NULL;
        cur = head;
        while (c--) {
            auto r = reverseOneGroup(cur, k);
            if (prev)
                prev->next = r.first;
            prev = cur;
            cur = r.second;
            if (!res) res = r.first;
        }
        prev->next = cur;

        return res;
    }

    pair<ListNode*, ListNode*> reverseOneGroup(ListNode* head, int k) {
        ListNode* cur = head, *prev = NULL, *next = NULL;
        while (k--) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return {prev, next};
    }
};

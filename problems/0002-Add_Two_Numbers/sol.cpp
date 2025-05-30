/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/add-two-numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode* res = new ListNode(-1);
        ListNode* cur = res;
        while (l1 || l2) {
            int l1val = l1 ? l1->val : 0;
            int l2val = l2 ? l2->val : 0;
            int val = l1val + l2val + carry;
            ListNode* n = new ListNode(val % 10);
            carry = val / 10;
            cur->next = n;
            cur = n;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }

        if (carry) {
            cur->next = new ListNode(1);
        }

        return res->next;
    }
};

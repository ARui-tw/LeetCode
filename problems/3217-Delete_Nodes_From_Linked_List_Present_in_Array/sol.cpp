/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array
 * Runtime: 95 ms (71.38%)
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* res = new ListNode();
        res->next = head;
        ListNode* cur = res;

        unordered_set<int> us;
        for (auto& num : nums) {
            us.insert(num);
        }

        while (cur->next) {
            if (us.count(cur->next->val)) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }


        return res->next;
    }
};

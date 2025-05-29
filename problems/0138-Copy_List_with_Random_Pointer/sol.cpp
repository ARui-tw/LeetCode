/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/copy-list-with-random-pointer
 * Runtime: 3 ms (92.06%)
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        unordered_map<Node*, Node*> um;
        Node* res = new Node(head->val);
        um[head] = res;

        Node* oc = head, *nc = res;
        while (oc->next) {
            oc = oc->next;
            Node* n = new Node(oc->val);
            um[oc] = n;
            nc->next = n;
            nc = n;
        }

        oc = head;
        nc = res;
        while (oc) {
            if (oc->random) {
                nc->random = um[oc->random];
            }
            oc = oc->next;
            nc = nc->next;
        }

        
        return res;
    }
};

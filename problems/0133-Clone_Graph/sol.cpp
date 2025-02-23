/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/clone-graph
 * Runtime: 0 ms (100.00%)
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        queue<Node*> que;
        vector<Node*> vec(101, nullptr);
        Node* dummy = new Node();
        Node* n = new Node(node->val, node->neighbors);
        dummy->neighbors.push_back(n);

        que.push(dummy);

        while (!que.empty()) {
            Node* top = que.front();
            que.pop();
            vector<Node*> newNeighbor = vector<Node*>();

            for (Node *neighbor : top->neighbors) {
                if (!vec[neighbor->val]) {
                    Node* n = new Node(neighbor->val, neighbor->neighbors);
                    vec[neighbor->val] = n;
                    que.push(n);
                }
                newNeighbor.push_back(vec[neighbor->val]);
            }
            top->neighbors = newNeighbor;
        }

        return dummy->neighbors[0];
    }
};

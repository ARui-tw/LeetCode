/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/lru-cache
 * Runtime: 79 ms (62.18%)
 */

class LRUCache {
    typedef struct Node {
        int val;
        int key;
        struct Node* nxt;
        struct Node* prev;
    } Node_t;
    unordered_map<int, Node_t*> um;
    int cap;
    Node_t* head;
public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node_t();
        head->nxt = head;
        head->prev = head;
    }
    
    int get(int key) {
        if (!um.count(key)) return -1;
        auto cur = um[key];

        cur->prev->nxt = cur->nxt;
        cur->nxt->prev = cur->prev;

        cur->prev = head;
        cur->nxt = head->nxt;
        head->nxt->prev = cur;
        head->nxt = cur;
        
        return cur->val;
    }
    
    void put(int key, int value) {
        Node_t* cur;
        if (um.count(key)) {
            cur = um[key];
            cur->prev->nxt = cur->nxt;
            cur->nxt->prev = cur->prev;
        } else {
            cur = new Node_t();
            um[key] = cur;
            cur->key = key;
        }

        cur->val = value;

        cur->prev = head;
        cur->nxt = head->nxt;
        head->nxt->prev = cur;
        head->nxt = cur;

        if (um.size() > cap) {
            auto last = head->prev;
            last->prev->nxt = last->nxt;
            last->nxt->prev = last->prev;
            um.erase(last->key);
            delete last;
        }

        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/find-median-from-data-stream
 * Runtime: 40 ms (93.47%)
 */

class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() {
        
    }

    void addNum(int num) {

        if (left.empty() || num <= left.top()) {
            // printf("Push %d to left\n", num);
            left.push(num);
        } else {
            // printf("Push %d to right\n", num);
            right.push(num);
        }

        while (right.size() > left.size()) {
            auto top = right.top();
            // printf("Moving %d to left\n", top);
            right.pop();
            left.push(top);
        }

        while ((int)left.size() - (int)right.size() > 1) {
            auto top = left.top();
            // printf("Moving %d to right\n", top);
            left.pop();
            right.push(top);
        }
    }
    
    double findMedian() {
        if ((left.size() + right.size()) & 1) {
            return left.top();
        } else {
            return (double)(left.top() + right.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/finding-pairs-with-a-certain-sum
 * Runtime: 50 ms (95.41%)
 */

class FindSumPairs {
    unordered_map<int, int> um1;
    unordered_map<int, int> um2;
    vector<int> nums2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (auto& n : nums1) {
            um1[n]++;
        }

        for (auto& n : nums2) {
            um2[n]++;
        }

        this->nums2 = nums2;
    }
    
    void add(int index, int val) {
        um2[nums2[index]]--;
        nums2[index] += val;
        um2[nums2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for (auto& [val, count] : um1) {
            int tar = tot - val;
            if (um2.count(tar)) {
                res += count * um2[tar];
            }
        }

        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

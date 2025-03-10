/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii
 * Runtime: 119 ms (96.16%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
    long long count(string word, int k) {
        int n = word.size();
        const char vow[] = {'a', 'e', 'i', 'o', 'u'};
        int vows[] = {0, 0, 0, 0, 0};
        int vowCount = 0;
        int tail = 0;
        bool vowFlag = false;
        long long res = 0;

        for (int i = 0; i < n; i++) {
            vowFlag = false;
            for (int j = 0; j < 5; j++) {
                if (word[i] == vow[j]) {
                    if (vows[j] == 0) {
                        vowCount++;
                    }
                    vows[j]++;
                    vowFlag = true;
                    break;
                }
            }


            if (!vowFlag) {
                k--;
            }

            while (k <= 0 && vowCount == 5) {
                res += n - i;

                vowFlag = false;
                for (int j = 0; j < 5; j++) {
                    if (word[tail] == vow[j]) {
                        if (--vows[j] == 0) vowCount--;
                        vowFlag = true;
                        break;
                    }
                }
                if (!vowFlag) k++;
                tail++;
            }
        }

        return res;
    }
public:
    long long countOfSubstrings(string word, int k) {
        return count(word, k) - count(word, k + 1);
    }
};

#include <vector>

class Solution {
  public:
    std::vector<int> lexicalOrder(int n) {
        // return all the numbers in the range [1, n] sorted in lexicographical
        // order algo should be in linear time and constant space
        std::vector<int> res;
        int current = 1;

        for (int i = 0; i < n; i++) {
            res.push_back(current);
            if (current * 10 <= n) {
                current *= 10;
            } else {
                while (current % 10 == 9 || current + 1 > n) {
                    current /= 10;
                }
                current++;
            }
        }

        return res;
    }
};
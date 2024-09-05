#include <vector>

class Solution {
  public:
    std::vector<int> missingRolls(std::vector<int>& rolls, int mean, int n) {
        auto rolls_sum = sum(rolls);
        auto target_sum = mean * (n + rolls.size()) - rolls_sum;
        int value = target_sum / n;
        int rem = target_sum % n;

        if (value <= 0 || value > 6) {
            return {};
        }

        std::vector<int> res(n, value);

        for (int i = 0; i < rem; i++) {
            res[i]++;
            if (res[i] > 6) {
                return {};
            }
        }

        return res;
    }

    int sum(std::vector<int>& rolls) {
        int res = 0;

        for (const auto& roll : rolls) {
            res += roll;
        }

        return res;
    }
};

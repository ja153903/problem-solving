#include "lib/string_ops.h"
#include <bitset>
#include <string>

class Solution {
  public:
    std::string convertDateToBinary(std::string date) {
        std::string res;
        auto parts = split_by(date, "-");
        for (int i = 0; i < parts.size(); i++) {
            auto num = std::stoi(parts[i]);
            std::bitset<32> x(num);
            parts[i] = x.to_string();
            parts[i].erase(0, parts[i].find_first_not_of("0"));
            res += parts[i];
            if (i < parts.size() - 1) {
                res += "-";
            }
        }

        return res;
    }
};

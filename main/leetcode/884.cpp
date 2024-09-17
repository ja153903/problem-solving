#include "lib/string_ops.h"
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<std::string> uncommonFromSentences(std::string s1,
                                                   std::string s2) {
        std::unordered_map<std::string, int> counter;
        std::vector<std::string> res;

        auto s1_by_whitespace = split_by(s1, " ");
        auto s2_by_whitespace = split_by(s2, " ");

        // find all the strings that only occur once
        for (const auto& s : s1_by_whitespace) {
            counter[s]++;
        }

        for (const auto& s : s2_by_whitespace) {
            counter[s]++;
        }

        for (const auto& [k, v] : counter) {
            if (v == 1) {
                res.push_back(k);
            }
        }

        return res;
    }
};

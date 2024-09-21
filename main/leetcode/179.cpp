#include "lib/string_ops.h"

#include <string>
#include <vector>

class Solution {
  public:
    std::string largestNumber(std::vector<int>& nums) {
        std::vector<std::string> nums_as_str;
        for (const auto& num : nums) {
            nums_as_str.push_back(std::to_string(num));
        }

        // custom sort is used here
        // if a + b > b + a, then this means that a should come before b
        // in our array
        // the way comparators work here is that for the vector to be a sorted
        // sequence it should be known that fn(a, b) > fn(b, a)
        std::ranges::sort(nums_as_str,
                          [](const std::string& a, const std::string& b) {
                              return (a + b) > (b + a);
                          });

        if (nums_as_str[0] == "0") {
            return "0";
        }

        return join(nums_as_str, "");
    }
};
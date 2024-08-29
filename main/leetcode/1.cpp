#include <iostream>
#include <unordered_map>
#include <vector>

void print_result(std::vector<int>& result) {
    std::cout << "[ ";

    for (const auto& num : result) {
        std::cout << num << " ";
    }

    std::cout << "]" << std::endl;
}

class Solution {
  public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            if (seen.find(target - nums[i]) != seen.end()) {
                return {seen[target - nums[i]], i};
            }

            seen[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    Solution s;

    // Case 1
    auto test_case = std::vector<int>{2, 7, 11, 15};
    auto target = 9;
    auto result = s.twoSum(test_case, target);

    print_result(result);

    // Case 2
    test_case = std::vector<int>{3, 2, 4};
    target = 6;
    result = s.twoSum(test_case, target);

    print_result(result);

    return 0;
}

#include <cctype>
#include <iostream>
#include <string>

class Solution {
  public:
    bool isPalindrome(std::string s) {
        std::string cleaned;

        for (int i = 0; i < s.length(); i++) {
            if (std::isalnum(s[i])) {
                cleaned += std::tolower(s[i]);
            }
        }

        auto size = cleaned.length();

        for (int i = 0; i < size / 2; i++) {
            if (cleaned[i] != cleaned[size - i - 1]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;

    // Case 1
    std::string str = "A man, a plan, a canal: Panama";
    std::cout << s.isPalindrome(str) << std::endl;

    return 0;
}

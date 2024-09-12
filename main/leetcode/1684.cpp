#include <string>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int countConsistentStrings(std::string allowed,
                               std::vector<std::string>& words) {
        std::unordered_set<char> unique_chars(allowed.begin(), allowed.end());

        int result = 0;
        for (int i = 0; i < words.size(); i++) {
            bool has_all_chars = true;

            for (int j = 0; j < words[i].length(); j++) {
                if (!unique_chars.contains(words[i][j])) {
                    has_all_chars = false;
                    break;
                }
            }

            if (has_all_chars) {
                result++;
            }
        }

        return result;
    }
};

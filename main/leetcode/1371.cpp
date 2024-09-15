#include "lib/char_ops.cpp"

#include <string>
#include <unordered_map>

class Solution {
  public:
    int findTheLongestSubstring(std::string s) {
        std::unordered_map<char, int> count;
        count['a'] = 1;
        count['e'] = 2;
        count['i'] = 4;
        count['o'] = 8;
        count['u'] = 16;

        std::unordered_map<int, int> first_occurence;
        first_occurence[0] = -1;

        int mask = 0;
        int max_len = 0;

        for (int i = 0; i < s.length(); i++) {
            if (is_vowel(s[i])) {
                mask ^= count[s[i]];
            }

            if (first_occurence.find(mask) != first_occurence.end()) {
                max_len = std::max(max_len, i - first_occurence[mask]);
            } else {
                first_occurence[mask] = i;
            }
        }

        return max_len;
    }
};
#include <string>

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool has_vowel(std::string s) {
    for (const auto& c : s) {
        if (is_vowel(c)) {
            return true;
        }
    }

    return false;
}
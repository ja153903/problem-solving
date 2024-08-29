#include "lib/string_ops.h"

#include <algorithm>
#include <string>
#include <vector>

std::vector<std::string> split_by(std::string s, std::string delimiter) {
    std::vector<std::string> parts;
    auto n = s.length();

    int i = 0;

    while (i < n) {
        auto pos = s.find(delimiter, i);

        // Collect the substring based on where we were
        std::string part;
        auto upper_bound = std::min(pos, n);
        for (int j = i; j < upper_bound; j++) {
            part += s[j];
        }
        parts.push_back(part);

        if (pos == std::string::npos) {
            break;
        }

        i = pos + 1;
    }

    return parts;
}

#include <iostream>
#include <string>

#include "lib/aoc_file_io.h"

int scan_for_level(std::string s);
int get_pos_for_first_negative_level(std::string s);

int main() {
    std::string pathname = "main/advent_of_code/2015/1/data.in";

    std::string data = read_file_into_str(pathname);

    // Part 1
    auto part1 = scan_for_level(data);

    std::cout << "AoC 2015 - Day 1 - Part 1: " << part1 << std::endl;

    auto part2 = get_pos_for_first_negative_level(data);

    std::cout << "AoC 2015 - Day 1 - Part 2: " << part2 << std::endl;

    return 0;
}

int scan_for_level(std::string s) {
    int result = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            result++;
        }

        if (s[i] == ')') {
            result--;
        }
    }

    return result;
}

int get_pos_for_first_negative_level(std::string s) {
    int level = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            level++;
        }

        if (s[i] == ')') {
            level--;
        }

        if (level < 0) {
            return i + 1;
        }
    }

    return 0;
}

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "lib/aoc_file_io.h"

std::string read_file_into_str(std::string pathname) {
    std::ifstream t(pathname);
    std::stringstream buffer;

    if (t.fail()) {
        std::cout << "Something went wrong reading the file: " << std::endl;
        return "";
    }

    buffer << t.rdbuf();

    return buffer.str();
}

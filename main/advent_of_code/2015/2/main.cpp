#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "lib/aoc_file_io.h"
#include "lib/string_ops.h"

typedef long long ll;
typedef std::tuple<ll, ll, ll> dim_t;

dim_t get_dimensions(std::string line);
std::vector<dim_t> parse_input(std::string input);

ll get_surface_area(dim_t dim);
ll get_sm_area(dim_t dim);
ll get_volume(dim_t dim);
ll get_sm_perim(dim_t dim);

int main() {
    std::string pathname = "main/advent_of_code/2015/2/data.in";

    std::string data = read_file_into_str(pathname);

    auto dimensions = parse_input(data);

    auto part1 = 0;

    for (const auto& dim : dimensions) {
        part1 += get_surface_area(dim) + get_sm_area(dim);
    }

    std::cout << "AoC 2015 - Day 2 - Part 1: " << part1 << std::endl;

    auto part2 = 0;

    for (const auto& dim : dimensions) {
        part2 += get_volume(dim) + get_sm_perim(dim);
    }

    std::cout << "AoC 2015 - Day 2 - Part 2: " << part2 << std::endl;

    return 0;
}

dim_t get_dimensions(std::string line) {
    auto parts = split_by(line, "x");

    auto w = std::stoi(parts[0]);
    auto h = std::stoi(parts[1]);
    auto l = std::stoi(parts[2]);

    return std::make_tuple(w, h, l);
}

std::vector<dim_t> parse_input(std::string input) {
    std::vector<dim_t> dims;

    auto lines = split_by(input, "\n");

    for (const auto& line : lines) {
        dims.push_back(get_dimensions(line));
    }

    return dims;
}

ll get_surface_area(dim_t dim) {
    const auto [w, l, h] = dim;
    return 2 * w * l + 2 * w * h + 2 * l * h;
}

ll get_sm_area(dim_t dim) {
    const auto [w, l, h] = dim;
    return std::min(std::min(w * l, w * h), l * h);
}

ll get_volume(dim_t dim) {
    const auto [w, l, h] = dim;
    return w * l * h;
}

ll get_sm_perim(dim_t dim) {
    const auto [w, l, h] = dim;
    return std::min(std::min(2 * w + 2 * l, 2 * w + 2 * h), 2 * l + 2 * h);
}

#include "lib/leetcode_ds.h"
#include <string>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        std::vector<std::vector<int>> grid(m, std::vector<int>(n, -1));

        int row = 0;
        int col = 0;

        int up_b = 0;
        int down_b = m - 1;
        int left_b = 0;
        int right_b = n - 1;

        std::string dir = "right";

        while (head) {
            grid[row][col] = head->val;
            head = head->next;

            if (head) {
                const auto [nrow, ncol, ndir, nup_b, ndown_b, nleft_b,
                            nright_b] =
                    get_next_coordinate(row, col, dir, up_b, down_b, left_b,
                                        right_b);
                row = nrow;
                col = ncol;
                dir = ndir;

                up_b = nup_b;
                down_b = ndown_b;
                left_b = nleft_b;
                right_b = nright_b;
            }
        }

        return grid;
    }

    std::tuple<int, int, std::string, int, int, int, int>
    get_next_coordinate(int row, int col, std::string dir, int up_b, int down_b,
                        int left_b, int right_b) {
        if (dir == "right") {
            auto ncol = col + 1;
            if (ncol > right_b) {
                return get_next_coordinate(row, col, "down", up_b + 1, down_b,
                                           left_b, right_b);
            }

            return std::make_tuple(row, ncol, dir, up_b, down_b, left_b,
                                   right_b);
        }

        if (dir == "down") {
            auto nrow = row + 1;
            if (nrow > down_b) {
                return get_next_coordinate(row, col, "left", up_b, down_b,
                                           left_b, right_b - 1);
            }

            return std::make_tuple(nrow, col, dir, up_b, down_b, left_b,
                                   right_b);
        }

        if (dir == "left") {
            auto ncol = col - 1;
            if (ncol < left_b) {
                return get_next_coordinate(row, col, "up", up_b, down_b - 1,
                                           left_b, right_b);
            }

            return std::make_tuple(row, ncol, dir, up_b, down_b, left_b,
                                   right_b);
        }

        auto nrow = row - 1;
        if (nrow < up_b) {
            return get_next_coordinate(row, col, "right", up_b, down_b,
                                       left_b + 1, right_b);
        }

        return std::make_tuple(nrow, col, dir, up_b, down_b, left_b, right_b);
    }

    std::string update_direction(std::string dir) {
        if (dir == "right")
            return "down";

        if (dir == "down")
            return "left";

        if (dir == "left")
            return "up";

        return "down";
    }
};

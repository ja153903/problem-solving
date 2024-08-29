#include <vector>

typedef std::vector<std::vector<int>> grid_t;

class Solution {
  public:
    int countSubIslands(grid_t& a, grid_t& b) {
        int res = 0;

        for (int i = 0; i < b.size(); i++) {
            for (int j = 0; j < b[i].size(); j++) {
                if (b[i][j] == 1) {
                    int total_size = 0;
                    int size = 0;
                    dfs(a, b, i, j, total_size, size);

                    if (total_size == size) {
                        res++;
                    }
                }
            }
        }

        return res;
    }

    void dfs(grid_t& a, grid_t& b, int row, int col, int& total_size,
             int& size) {
        if (row < 0 || col < 0 || row >= a.size() || col >= a[0].size() ||
            b[row][col] != 1) {
            return;
        }

        total_size++;
        if (a[row][col] == b[row][col]) {
            size++;
        }

        a[row][col] = -1;
        b[row][col] = -1;

        dfs(a, b, row + 1, col, total_size, size);
        dfs(a, b, row - 1, col, total_size, size);
        dfs(a, b, row, col + 1, total_size, size);
        dfs(a, b, row, col - 1, total_size, size);
    }
};

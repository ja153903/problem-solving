#include <vector>

typedef std::vector<std::vector<char>> grid_t;

class Solution {
  public:
    int numIslands(grid_t& grid) {
        int result = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    result++;
                }
            }
        }

        return result;
    }

    void dfs(grid_t& a, int r, int c) {
        if (r < 0 || c < 0 || r >= a.size() || c >= a[0].size() ||
            a[r][c] != '1') {
            return;
        }

        a[r][c] = '#';

        dfs(a, r + 1, c);
        dfs(a, r - 1, c);
        dfs(a, r, c + 1);
        dfs(a, r, c - 1);
    }
};

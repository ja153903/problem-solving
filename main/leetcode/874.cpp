#include <string>
#include <utility>
#include <vector>

class Solution {
  public:
    int robotSim(std::vector<int>& commands,
                 std::vector<std::vector<int>>& obstacles) {
        std::pair<int, int> coord = std::make_pair(0, 0);
        // state => NORTH | SOUTH | EAST | WEST
        std::string state = "NORTH";
        int max_dist = 0;

        for (const auto& command : commands) {
            std::string next_state = state;

            if (command == -1 || command == -2) {
                next_state = get_state_after_pivot(state, command);
            }

            std::pair<int, int> next_coord = coord;

            for (int i = 0; i < command; i++) {
                next_coord =
                    get_coord_after_state_update(next_coord, next_state, 1);
                bool is_obstacle = false;

                for (const auto& obstacle : obstacles) {
                    if (obstacle[0] == next_coord.first &&
                        obstacle[1] == next_coord.second) {
                        is_obstacle = true;
                        break;
                    }
                }

                if (is_obstacle) {
                    // revert the step
                    next_coord = get_coord_after_state_update(next_coord,
                                                              next_state, -1);
                    break;
                }
            }

            coord = next_coord;
            state = next_state;

            max_dist = std::max(max_dist, approx_dist(coord));
        }

        return max_dist;
    }

    std::string get_state_after_pivot(std::string state, int pivot) {
        if (state == "NORTH") {
            if (pivot == -2) {
                return "WEST";
            }

            return "EAST";
        }

        if (state == "SOUTH") {
            if (pivot == -2) {
                return "EAST";
            }

            return "WEST";
        }

        if (state == "EAST") {
            if (pivot == -2) {
                return "NORTH";
            }

            return "SOUTH";
        }

        // NOTE: State is WEST
        if (pivot == -2) {
            return "SOUTH";
        }

        return "NORTH";
    }

    std::pair<int, int>
    get_coord_after_state_update(std::pair<int, int> current,
                                 std::string direction, int steps) {
        if (direction == "NORTH")
            return std::make_pair(current.first, current.second + steps);

        if (direction == "SOUTH")
            return std::make_pair(current.first, current.second - steps);

        if (direction == "EAST")
            return std::make_pair(current.first + steps, current.second);

        return std::make_pair(current.first - steps, current.second);
    }

    int approx_dist(std::pair<int, int> coord) {
        return coord.first * coord.first + coord.second * coord.second;
    }
};

#include <bitset>

class Solution {
  public:
    int minBitFlips(int start, int goal) {
        // XOR to get the number of different bits
        return std::bitset<32>(start ^ goal).count();
    }
};

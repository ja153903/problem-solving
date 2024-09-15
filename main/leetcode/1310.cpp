#include <vector>

class Solution {
  public:
    std::vector<int> xorQueries(std::vector<int>& arr,
                                std::vector<std::vector<int>>& queries) {
        std::vector<int> result(queries.size(), 0);

        // A property of XOR operations that we want to apply here
        // is that we can unapply XOR by just applying the same operation again
        // What this means for this problem is that if we keep track of a
        // prefix XOR vector then to unapply certain parts of it, we just need
        // to remove the queries we dont want
        std::vector<int> prefix(arr.size(), 0);

        for (int i = 0; i < arr.size(); i++) {
            if (i == 0) {
                prefix[i] = arr[i];
            } else {
                prefix[i] = prefix[i - 1] ^ arr[i];
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            result[i] = prefix[end];

            if (start > 0) {
                result[i] ^= prefix[start - 1];
            }
        }

        return result;
    }
};

#include <stack>
#include <string>

class Solution {
  public:
    bool isValid(std::string s) {
        std::stack<char> stk;

        for (const auto& ch : s) {
            if (ch == '(') {
                stk.push(')');
            } else if (ch == '{') {
                stk.push('}');
            } else if (ch == '[') {
                stk.push(']');
            } else if (stk.empty() || stk.top() != ch) {
                return false;
            } else {
                stk.pop();
            }
        }

        return stk.empty();
    }
};

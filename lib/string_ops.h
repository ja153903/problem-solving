#ifndef STRING_OPS_H_
#define STRING_OPS_H_

#include <string>
#include <vector>

std::vector<std::string> split_by(std::string s, std::string delimiter);
std::string join(std::vector<std::string> s, std::string delimiter);

#endif // !STRING_OPS_H_

#pragma "once"

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

typedef std::unordered_map<char, std::vector<std::string>> font_t;
typedef std::vector<std::string> text_t;

std::ostream& operator<<(std::ostream& l, const text_t& r){
    for (int i = 0; i < r.size(); ++i) {
        l << r[i] << "\n";
    }
    return l;
}
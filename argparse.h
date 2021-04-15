#pragma "once"

#include <algorithm>
#include <string>
#include <vector>

class ArgParse {
private:
    std::vector<std::string> args;
public:
    ArgParse(int argc, char ** argv) {
        for (int i = 1; i < argc; ++i) {
            args.push_back(std::string(argv[i]));
        }
    }

    const std::string& get_arg(const std::string& argt) const {
        auto it = std::find(args.begin(), args.end(), argt);
        if (it == args.end() || ++it == args.end()) {
            static const std::string empty_string("");
            return empty_string;
        }
        return *it;
    }

    bool exists(const std::string& argt) const {
        auto it = std::find(args.begin(), args.end(), argt);
        return !(it == args.end() || ++it == args.end());
    }
};

#include <iostream>

#include "argparse.hpp"
#include "fancy.hpp"

int main(int argc, char ** argv) {
    ArgParse parser(argc, argv);

    font_t font;
    
    for (char c = 'a'; c <= 'z'; ++c) {
        font[c] = std::string("<") + c + std::string(">");
    }

    FancyText fancy_text(parser.get_arg_i(0), font);
    std::string fancy = fancy_text.get_fancy();

    std::cout << fancy << "\n";
    return 0;
}

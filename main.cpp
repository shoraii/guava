#include <iostream>

#include "argparse.hpp"
#include "fancy.hpp"

int main(int argc, char ** argv) {
    ArgParse parser(argc, argv);

    init_font();
    int spacing = 0;
    std::string sps = parser.get_arg("-sp");
    if (sps != "") {
        try {
            spacing = std::stoi(sps);
        } catch(const std::exception& e) {
            spacing = 0;
        }
    }
    std::string raw = parser.get_arg("-i");
    if (raw == "") {
        raw = parser.get_arg_i(0);
    }
    FancyGen fancy_text(raw, default_font, spacing);
    text_t fancy = fancy_text.get_fancy();

    std::cout << fancy;
    return 0;
}

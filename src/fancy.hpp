#pragma "once"

#include "initfonts.hpp"

class FancyGen {
private:
    std::string raw;
    Font font;
    text_t fancy;

    int spacing = 0;
    bool fancied = false;

    void make_fancy() {
        fancy.resize(font.height);
        for (int i = 0; i < font.height; ++i) {
            for (int j = 0; j < raw.size(); ++j) {
                char to_print = raw[j];
                if (!font.case_sensitive) {
                    to_print = std::tolower(to_print);
                }
                if (font.typeface.count(to_print) > 0) {
                    fancy[i] += font.typeface[to_print][i];
                }
                for (int k = 0; k < spacing; ++k) {
                    fancy[i] += " ";
                }
            }
        }
    }

public:
    FancyGen() {

    }

    FancyGen(const std::string& text, const Font& font, int spacing) {
        raw = text;
        this->font = font;
        this->spacing = spacing;
    }

    const text_t& get_fancy() {
        if (fancied) {
            return fancy;
        }
        make_fancy();
        return fancy;
    }
};
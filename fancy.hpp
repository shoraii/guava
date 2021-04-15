#pragma "once"

#include <string>
#include <vector>
#include <unordered_map>

typedef std::unordered_map<char, std::string> font_t;

class FancyText {
private:
    std::string raw;

    std::string fancy;
    bool fancied = false;
    
    font_t font;
    //int style (bold, italic, underline, etc.)

    std::string fancy_letter(char letter) {
        if (font.count(letter) == 0) {
            return std::string("") + letter;
        }
        return font[letter];
    }

    void make_fancy() {
        for (int i = 0; i < raw.size(); ++i) {
            fancy += fancy_letter(raw[i]);
        }
    }

public:
    FancyText() {

    }

    FancyText(const std::string& text, const font_t& font) {
        raw = text;
        this->font = font;
    }

    const std::string& get_fancy() {
        if (fancied) {
            return fancy;
        }
        make_fancy();
        return fancy;
    }
};
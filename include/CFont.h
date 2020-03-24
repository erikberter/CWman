//
// Created by whiwho on 24/03/2020.
//

#ifndef WINDOW_MANAGER_CFONT_H
#define WINDOW_MANAGER_CFONT_H

#include <string>
#include <SDL_pixels.h>

class CFont{
private:
    std::string font_file;
    SDL_Color font_color = {0,0,0,0};
public:

    CFont() : font_file{"../res/font/Roboto/Roboto-Regular.ttf"}{};

    std::string get_font(){return font_file;};
    void set_font(std::string& font_file_t){font_file = font_file_t;};

    SDL_Color get_font_color(){return font_color;};

};

#endif //WINDOW_MANAGER_CFONT_H

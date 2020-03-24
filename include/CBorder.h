//
// Created by whiwho on 24/03/2020.
//

#ifndef WINDOW_MANAGER_CBORDER_H
#define WINDOW_MANAGER_CBORDER_H

#include <SDL_pixels.h>

class CBorder{
private:

    int border_size = 1;

    SDL_Color border_color = {0,0,0,255};
public:
    CBorder() = default;
    CBorder(const CBorder &border_t){
        border_size = border_t.border_size;
        border_color = border_t.border_color;
    }

    ~CBorder() = default;


    void set_border(const CBorder &border_t){
        border_size = border_t.border_size;
        border_color = border_t.border_color;
    }
    void set_border(int border_size_t, SDL_Color border_color_t){
        border_size = border_size_t;
        border_color;
    }
    void set_size(int border_size_t){
        border_size = border_size_t;
    }
    void set_color(SDL_Color border_color_t){
        border_color = border_color_t;
    }

    SDL_Color get_color(){return border_color;};
};

#endif //WINDOW_MANAGER_CBORDER_H

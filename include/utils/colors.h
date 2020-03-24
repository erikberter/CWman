//
// Created by whiwho on 24/03/2020.
//

#ifndef WINDOW_MANAGER_COLORS_H
#define WINDOW_MANAGER_COLORS_H

#include <SDL_types.h>
#include <SDL_pixels.h>
#include <algorithm>

SDL_Color black = {0,0,0};

Uint8 check_bound(int a){ return static_cast<Uint8>(std::max( 0, std::min(255, a)));}
Uint8 check_bound(Uint8 a){ return static_cast<Uint8>(std::max( 0, std::min(255, static_cast<int>(a))));}

static SDL_Color int_to_SDL_Color(int r, int g, int b, int a){
    return SDL_Color({check_bound(r),check_bound(g),check_bound(b),check_bound(a)});
}

static SDL_Color SDL_Color_dsp(SDL_Color color, int dsp){
    return int_to_SDL_Color(static_cast<int>(color.r)+dsp,static_cast<int>(color.g)+dsp,
            static_cast<int>(color.b)+dsp,static_cast<int>(color.a));
}
#endif //WINDOW_MANAGER_COLORS_H

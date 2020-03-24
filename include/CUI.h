//
// Created by whiwho on 24/03/2020.
//

#ifndef WINDOW_MANAGER_CUI_H
#define WINDOW_MANAGER_CUI_H

#include <algorithm>

#include <SDL.h>
#include <iostream>
#include "CDimension.h"

class CUI{
private:
    Dimension min_size;
    Dimension act_size;

    Position coords;

    SDL_Rect dst;

    SDL_Texture* tex;
    bool tex_loaded;

    CBorder border;
    SDL_Color bg_color = {233,233,233,255};
public:
    CUI() : min_size{Dimension{100,100}}, act_size{Dimension{100,100}},
        coords{Position{0,0}}, tex_loaded{false}, tex{nullptr}{dst = d_to_R(coords,act_size);};
    ~CUI(){SDL_DestroyTexture(tex);};

    Dimension get_minimum_size(){return min_size;};
    Dimension get_actual_size(){return act_size;};

    void set_minimum_size(Dimension dim){
        min_size = dim;
        // Check if actual size is less than minimum size
        act_size.w = std::max(min_size.w,dim.w);
        act_size.h = std::max(min_size.h,dim.h);
        dst=d_to_R(coords, act_size);
    };
    void set_actual_size(Dimension dim){
        act_size.w = std::max(min_size.w,dim.w);
        act_size.h = std::max(min_size.h,dim.h);
        dst=d_to_R(coords, act_size);
    }

    Position* get_coords(){return &coords;};
    void set_pos(int x, int y){coords = {x,y};dst=d_to_R(coords, act_size);};
    void set_pos(Position p){coords = p;dst=d_to_R(coords, act_size);};

    SDL_Rect* get_dst(){
        return &dst;
    }

    bool is_tex_loaded(){return tex_loaded;};
    void set_tex_loaded(bool tex_loaded_t){tex_loaded = tex_loaded_t;}

    CBorder get_border(){return border;};

    void set_background_color(SDL_Color bg_color_t){bg_color = bg_color_t;};
    SDL_Color get_background_color(){return bg_color;};

    void set_tex(SDL_Texture* tex_t){tex = tex_t;tex_loaded = true;};

    void draw(SDL_Renderer* ren){
        // Fill Background color
        SDL_SetRenderDrawColor(ren, bg_color.r,bg_color.g,bg_color.b,255);
        SDL_RenderFillRect(ren, &dst);
        // Fill border
        SDL_Color border_color = border.get_color();
        SDL_SetRenderDrawColor(ren, border_color.r,border_color.g,border_color.b,255);
        SDL_RenderDrawRect(ren, get_dst());
        // Reset Color
        SDL_SetRenderDrawColor(ren, 255,255,255,255);
        if(tex_loaded)
            SDL_RenderCopy(ren, tex,NULL, &dst);

    };
};
#endif //WINDOW_MANAGER_CUI_H

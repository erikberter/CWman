//
// Created by whiwho on 24/03/2020.
//

#ifndef WINDOW_MANAGER_CABSTRACTBUTTON_H
#define WINDOW_MANAGER_CABSTRACTBUTTON_H

#include "CComponent.h"
#include "SDL.h"

#include <functional>
#include <algorithm>
#include <utils/colors.h>

class CAbstractButton : public CComponent{
private:

    // Component Metadata
    int button_temp = 0;

    // Component vals
    std::function<void(void)> action_listener = [](){};

    // Component Render

public:
    bool is_pressed = false;

    CAbstractButton() : CComponent() {};

    CAbstractButton(int pos_x, int pos_y) : CComponent(), is_pressed{false}{};

    ~CAbstractButton() = default;

    void input() override{
        if(is_pressed) return;
        SDL_PumpEvents();
        if(SDL_GetMouseState(NULL,NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)){
            int x, y;
            SDL_GetMouseState(&x, &y);
            SDL_Rect *coords = get_dst();
            if (coords->x < x && coords->x + coords->w > x && coords->y < y && coords->y + coords->h > y){
                is_pressed = true;
                button_temp = 3;
                SDL_Color bg_color = get_background_color();
                set_background(SDL_Color_dsp(bg_color,-30));
                action_listener();

            }

        }
    };
    void update() override{
        if(is_pressed){
            if(button_temp--==0){
                SDL_Color bg_color = get_background_color();
                is_pressed = false;
                set_background(SDL_Color_dsp(bg_color,30));
            }
        }
    };

    void draw(SDL_Renderer *ren) override{draw_CUI(ren);};

    void update_layout() override{};

    void set_action_listener(std::function<void(void)> function_t ){
        action_listener = function_t;
    };
};
#endif //WINDOW_MANAGER_CABSTRACTBUTTON_H

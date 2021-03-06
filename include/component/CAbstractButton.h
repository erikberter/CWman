#ifndef WINDOW_MANAGER_CABSTRACTBUTTON_H
#define WINDOW_MANAGER_CABSTRACTBUTTON_H

#include "CComponent.h"
#include "SDL.h"

#include <functional>
#include <algorithm>
#include <utils/colors.h>
#include <utils/collision.h>
#include <CMouse.h>


class CWindow;
class CAbstractButton : public CComponent{
private:

    std::function<void(CWindow*)> action_listener = nullptr;
    CWindow *win = nullptr;
    bool inside = false;

    void _set_pressed(bool pressed_t){
        if(pressed_t==pressed) return;
        if(!pressed_t) _react_button();

        set_background(SDL_Color_dsp(get_background_color(),
                                     (pressed_t) ? -30 : 30));
        pressed = !pressed;
        set_selected(pressed_t);
    }

    void _set_inside(bool inside_t){
        if(inside_t==inside) return;

        set_background(SDL_Color_dsp(get_background_color(),
                                     (inside_t) ? -10 : 10));
        inside = !inside;
    }

    void _react_button(){
        if(action_listener== nullptr || win == nullptr)
            return;
        action_listener(win);
    }
public:
    bool pressed = false;

    CAbstractButton() : CComponent() {};

    ~CAbstractButton() = default;

    void input() override{
        SDL_PumpEvents();
        if(!is_selectable()) return;
        if(is_inside_rect(get_dst(), CMouse::mouse_x, CMouse::mouse_y)){
            _set_pressed(CMouse::isClickLeft());
            _set_inside(!CMouse::isClickLeft());
        }else{
            if(pressed && !CMouse::isClickLeft()) _set_pressed(false);
            _set_inside(false);
        }
    };

    void update() override{};

    void draw(SDL_Renderer *ren) override{draw_CUI(ren);};

    void update_layout() override{};

    void set_action_listener(const std::function<void(CWindow*)>& function_t ){
        action_listener = function_t;
    };

    void set_window(CWindow *win_t){win = win_t;};


};
#endif //WINDOW_MANAGER_CABSTRACTBUTTON_H

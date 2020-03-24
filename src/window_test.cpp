//
// Created by whiwho on 24/03/2020.
//

#define SDL_MAIN_HANDLED

#include <CWindow.h>
#include "component/CButton.h"
int main(){
    CWindow win;
    CPanel *pan = new CPanel();
    CPanel *g_pan = new CPanel();
    g_pan->set_background({0,255,0,0});
    win.set_size(700,400);
    pan->set_background({255,0,0,0});
    pan->add(new CButton("Panel"));
    g_pan->add(new CButton("Pruebas"));
    g_pan->add(new CButton("Prueba2"));
    g_pan->add(pan);
    win.add(g_pan);
    win.init_window();
}
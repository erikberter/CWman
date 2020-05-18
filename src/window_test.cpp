#define SDL_MAIN_HANDLED

#include <CWindow.h>
#include <component/CTextBox.h>
#include <component/CScrollPanel.h>
#include <component/CBar.h>
#include "component/CButton.h"
#include "component/CLabel.h"

#include <string>
#include <layout/FlowLayout.h>

int main(){
    CWindow win;
    CPanel *pan = new CPanel();
    FlowLayout *flow = new FlowLayout();
    pan->set_layout(flow);
    for(int i = 0; i < 20; i++){
        pan->add(new CButton("Button " + std::to_string(i)));
    }
    win.add(pan);
    win.init_window();
    win.~CWindow();
}


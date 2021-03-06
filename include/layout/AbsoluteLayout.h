#ifndef WINDOWMANAGER_ABSOLUTE_LAYOUT_H
#define WINDOWMANAGER_ABSOLUTE_LAYOUT_H

#include "WindowLayout.h"

class AbsoluteLayout : public WindowLayout{

public:
    AbsoluteLayout(){
        change_layout(WindowLayout::LayoutType::ABSOLUTE);
    }
    void set_size(std::vector<CComponent*> component_list, CComponent* parent_panel) override;
};
#endif //WINDOWMANAGER_ABSOLUTE_LAYOUT_H

//
// Created by whiwho on 23/03/2020.
//

#ifndef DEUBER_COMPONENT_TEMPLATE_H
#define DEUBER_COMPONENT_TEMPLATE_H

#include <CComponent.h>

class CName : public CComponent{
private:

    // Component Metadata

    // Component Values

    // Component Renders
    SDL_Texture *tex;
public:
    CName() = default;
    ~CName() = default;

    // Runtime Handlers
    void input() override {};
    void update() override {};
    void draw(SDL_Renderer* ren) override {};

    void update_layout() override{};
};

#endif //DEUBER_COMPONENT_TEMPLATE_H

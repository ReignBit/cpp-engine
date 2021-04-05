#pragma once
#include "Component.h"

class DebugComponent :
    public Component {

public:
    DebugComponent();
    ~DebugComponent();

    virtual void start();
    virtual void update(float& dt);
    virtual void render(sf::RenderTarget& target);
};


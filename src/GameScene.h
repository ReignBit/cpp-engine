#pragma once
#include "Scene.h"
#include "GameObject.h"

class GameScene :
    public Scene {

public:
    GameScene(const char* id);
    ~GameScene();

    virtual void beginScene(Scene* from);
    virtual void endScene(Scene* to);
    virtual void onUpdate(float& dt);
};


#include <cstdlib>

#include "App.h"
#include "GameScene.h"

int main()
{
    App game;
    game.loadConfig("Resources/Config/config.ini");
    game.initWindow("First window!");


    GameScene testScene("Hello world");
    game.pushScene(&testScene);

    game.run();
    system("pause");

    return 0;
}
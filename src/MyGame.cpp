#include "MyGame.h"
#include "Canvas.cpp"
#include "GameEngine.cpp"

class MyGame {
    public:
        MyGame() {
            gameEngine = new GameEngine(new Canvas("Meu Jogo 2D", 800, 600));
        }

        ~MyGame() {
            gameEngine->~GameEngine();
            delete gameEngine;
            //delete canvas;
        }

        void run() {
            gameEngine->run();
        }

    private:
        GameEngine* gameEngine;
};

int main(int argc, char* argv[])
{
    MyGame jogo;
    jogo.run();
    return 0;
}
#include "./h/MyGame.h"
#include "Canvas.cpp"
#include "GameEngine.cpp"

/**
 * Class representing the Game (uses Canvas & GameEngine)
 */
class MyGame {
    public:
        /**
         * Constructor 
         */
        MyGame(int targetFPS) {
            canvas = new Canvas("Meu Jogo 2D", 800, 600);
            gameEngine = new GameEngine(canvas, targetFPS);
        }

        /**
         * Destructor
         */
        ~MyGame() {
            //clear game engine memory
            gameEngine->~GameEngine();

            //delete member variable
            delete gameEngine;

            //clear canvas memory
            canvas->~Canvas();

            //delete canvas
            delete canvas;
        }

        /**
         * Run the GameEngine
         */
        void run() {
            gameEngine->run();
        }

    private:
        Canvas* canvas; 
        GameEngine* gameEngine;
};


/**
 * Run
 */
int main(int argc, char* argv[]) {
    MyGame *jogo = new MyGame(60);
    jogo->run();
    return 0;
}
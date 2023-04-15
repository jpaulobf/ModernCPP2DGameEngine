#include "MeuJogo.h"
#include "Canvas.cpp"
#include "GameEngine.cpp"

class MeuJogo {
    public:
        MeuJogo() {
            canvas = new Canvas("Meu Jogo 2D", 800, 600);
            gameEngine = new GameEngine(canvas);
        }

        ~MeuJogo() {
            delete gameEngine;
            delete canvas;
        }

    private:
        Canvas* canvas;
        GameEngine* gameEngine;
};

int main(int argc, char* argv[])
{
    MeuJogo *jogo = new MeuJogo();
    return 0;
}
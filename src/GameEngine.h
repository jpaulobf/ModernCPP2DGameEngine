#pragma once

#include "Canvas.h"

class GameEngine {
    public:
        GameEngine(Canvas* canvas, int targetFPS);

        ~GameEngine();

        void update(float frametime);

        void render();

        void run();

        void controlKeys(SDL_Event event);

    private:
        Canvas* canvas;
        int targetFPS;
};
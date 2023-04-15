#pragma once

#include "Canvas.h"

class GameEngine {
    public:
        GameEngine(Canvas* canvas);

        ~GameEngine();

        void update(float frametime);

        void render();

        void run();

        void controlKeys(SDL_Event event);

    private:
        Canvas* canvas;
};
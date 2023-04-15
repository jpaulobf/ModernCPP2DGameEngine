#pragma once

#include <iostream>
#define SDL_MAIN_HANDLED
#include "include\SDL2\SDL.h"

class Canvas {

    public:
        Canvas(const std::string& title, int width, int height);

        ~Canvas();

        void clear();

        void present();

        void update(float frametime);

        void render();

        SDL_Renderer* getRenderer();

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};
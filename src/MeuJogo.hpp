#include <iostream>
#include <SDL.h>

class Canvas {

    public:
        Canvas(const std::string& title, int width, int height);

        ~Canvas();

        void clear();

        void present();

        void update(float frametime);

        void render();

        SDL_Renderer* getRenderer();
};
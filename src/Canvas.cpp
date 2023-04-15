#include "Canvas.h"

//------------------------IMPL-------------------------------------

Canvas::Canvas(const std::string& title, int width, int height) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Canvas::~Canvas() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Canvas::clear() {
    SDL_RenderClear(renderer);
}

void Canvas::present() {
    SDL_RenderPresent(renderer);
}

void Canvas::update(float frametime) {
    // Atualize a lógica específica do canvas aqui
    std::cout << "Update do Canvas - Frametime: " << frametime << " segundos" << std::endl;
}

void Canvas::render() {
    // Renderize os elementos do canvas aqui
    SDL_Renderer* renderer = getRenderer();
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

SDL_Renderer* Canvas::getRenderer() {
    return renderer;
}
#include "GameEngine.h"

//------------------------IMPL-------------------------------------

GameEngine::GameEngine(Canvas* canvas) {
    this->canvas = canvas;
}

GameEngine::~GameEngine() {
    // Faça a limpeza dos recursos do jogo aqui
    delete canvas;
}

void GameEngine::update(float frametime) {
    // Atualize a lógica do jogo aqui
    //std::cout << "Update do Jogo - Frametime: " << frametime << " segundos" << std::endl;

    // Chame o método update do Canvas
    canvas->update(frametime);
}

void GameEngine::render() {
    // Renderize os elementos do jogo aqui
    canvas->render();
}

void GameEngine::run() {
    bool quit = false;
    Uint64 currentTime = SDL_GetPerformanceCounter();
    Uint64 lastTime = 0;
    double deltaTime = 0;

    while (!quit) {
        lastTime = currentTime;
        currentTime = SDL_GetPerformanceCounter();
        deltaTime = (double)((currentTime - lastTime) * 1000 / (double)SDL_GetPerformanceFrequency()) / 1000.0;

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
                break;
            }
            // Realize o tratamento dos eventos do jogo aqui
            controlKeys(event);
        }

        update(deltaTime);
        render();
    }
}

void GameEngine::controlKeys(SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                std::cout << "Tecla para CIMA pressionada" << std::endl;
                break;
            case SDLK_DOWN:
                std::cout << "Tecla para BAIXO pressionada" << std::endl;
                break;
            case SDLK_LEFT:
                std::cout << "Tecla para ESQUERDA pressionada" << std::endl;
                break;
            case SDLK_RIGHT:
                std::cout << "Tecla para DIREITA pressionada" << std::endl;
                break;
            case SDLK_SPACE:
                std::cout << "Tecla ESPAÇO pressionada" << std::endl;
                break;
            default:
                break;
        }
    }
}
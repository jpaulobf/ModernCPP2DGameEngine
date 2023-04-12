#include <iostream>
#include <SDL.h>

class Canvas {
public:
    Canvas(const std::string& title, int width, int height) {
        SDL_Init(SDL_INIT_VIDEO);
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

    ~Canvas() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void clear() {
        SDL_RenderClear(renderer);
    }

    void present() {
        SDL_RenderPresent(renderer);
    }

    void update(float frametime) {
        // Atualize a lógica específica do canvas aqui
        std::cout << "Update do Canvas - Frametime: " << frametime << " segundos" << std::endl;
    }

    void render() {
        // Renderize os elementos do canvas aqui
        SDL_Renderer* renderer = getRenderer();
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_Renderer* getRenderer() {
        return renderer;
    }

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

class GameEngine {
public:
    GameEngine(Canvas* canvas) {
        this->canvas = canvas;
    }

    ~GameEngine() {
        // Faça a limpeza dos recursos do jogo aqui
    }

    void update(float frametime) {
        // Atualize a lógica do jogo aqui
        std::cout << "Update do Jogo - Frametime: " << frametime << " segundos" << std::endl;

        // Chame o método update do Canvas
        canvas->update(frametime);
    }

    void render() {
        // Renderize os elementos do jogo aqui
        canvas->render();
    }

    void run() {
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

    void controlKeys(SDL_Event event) {
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
};

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

}

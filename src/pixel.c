#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct app_t
{
    int running;
} app_t;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

static app_t app;

// Core // 

static void init_app(app_t *app)
{
    app->running = 1;
}

static void update_app(app_t *app)
{
    // Handle Input

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
            {
                app->running = 0;
            } break;

            default: break;
        }
    }
}

static void render_app(SDL_Renderer *renderer, app_t *app)
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 51, 77, 77, 255);
    SDL_RenderPresent(renderer);
}

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("Pixel",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    init_app(&app);

    while (app.running)
    {
        update_app(&app);
        render_app(renderer, &app);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

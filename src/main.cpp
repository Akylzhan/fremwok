#include <AppState.h>
#include <Texture.h>

#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_timer.h>

#include <iostream>

int SDL_AppInit(void **appstate, int argc, char **argv)
{
    auto *state = new AppState;
    *appstate = state;

    auto ret = static_cast<int>(state->Init());
    if (ret != SDL_APP_CONTINUE) {
        return ret;
    }

    state->AddObject(new Texture());

    return SDL_APP_CONTINUE;
}

int SDL_AppIterate(void *appstate)
{
    auto *state = static_cast<AppState *>(appstate);
    return static_cast<int>(state->Iterate());
}

int SDL_AppEvent(void *appstate, SDL_Event const *event)
{
    auto *state = static_cast<AppState *>(appstate);

    switch (event->type) {
        case SDL_EVENT_WINDOW_RESIZED :
            state->ResizeWindow(event->window.data1, event->window.data2);
            break;
        case SDL_EVENT_KEY_DOWN :
            std::cout << SDL_GetKeyName(event->key.keysym.sym) << std::endl;
            break;
        case SDL_EVENT_QUIT :
            return SDL_APP_SUCCESS;
        default :
            return SDL_APP_CONTINUE;
    }
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate)
{
    auto *state = static_cast<AppState *>(appstate);
    delete state;
}

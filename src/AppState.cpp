#include <AppState.h>

#include <Drawable.h>

#include <Corrade/Containers/GrowableArray.h>
#include <Corrade/Utility/Debug.h>

#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Platform/GLContext.h>

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_video.h>

AppState::AppState() = default;

AppState::~AppState()
{
    for (auto &drawable : objects) {
        delete drawable.release();
    }

    SDL_GL_DeleteContext(glContext);
    glContext = nullptr;
    delete magnumGlContext.release();
    SDL_DestroyWindow(window);
    window = nullptr;
}

AppState::AppStatus AppState::Init()
{
    if (SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER) != 0) {
        return AppStatus::FailureQuit;
    }

    window = SDL_CreateWindow("game", 800, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
    if (window == nullptr) {
        return AppStatus::FailureQuit;
    }

    glContext = SDL_GL_CreateContext(window);
    if (glContext == nullptr) {
        SDL_Log("%s", SDL_GetError());
        return AppStatus::FailureQuit;
    }

    magnumGlContext = Corrade::Containers::pointer(new Magnum::Platform::GLContext());
    return AppStatus::Continue;
}

AppState::AppStatus AppState::Iterate()
{
    Magnum::GL::defaultFramebuffer.clear(Magnum::GL::FramebufferClear::Color);
    for (auto &drawable : objects) {
        drawable->draw();
    }

    SDL_GL_SwapWindow(window);
    return AppStatus::Continue;
}

void AppState::ResizeWindow(int width, int height)
{
    auto viewport = Magnum::GL::defaultFramebuffer.viewport();
    viewport.right() = width;
    viewport.top() = height;
    Magnum::GL::defaultFramebuffer.setViewport(viewport);
}

void AppState::AddObject(Drawable *object)
{
    Corrade::Containers::arrayAppend(objects, Corrade::Containers::Pointer<Drawable>{object});
}
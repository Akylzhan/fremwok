#pragma once

#include <Corrade/Containers/Array.h>
#include <Corrade/Containers/Pointer.h>

#include <SDL3/SDL_video.h>

namespace Magnum::Platform
{
    class GLContext;
}

struct SDL_Window;
class Triangle;
class Drawable;

class AppState final
{
  public:
    enum class AppStatus : int {
        FailureQuit = -1,
        Continue = 0,
        SuccessQuit = 1,
    };

    AppState();
    AppState(AppState const &) = delete;
    AppState(AppState &&) = delete;
    AppState &operator=(AppState const &) = delete;
    AppState &operator=(AppState &&) = delete;
    ~AppState();

    AppStatus Init();
    AppStatus Iterate();
    void ResizeWindow(int width, int height);
    void AddObject(Drawable *object);

    SDL_GLContext glContext = nullptr;
    SDL_Window *window = nullptr;
    Corrade::Containers::Pointer<Magnum::Platform::GLContext> magnumGlContext = nullptr;
    Corrade::Containers::Array<Corrade::Containers::Pointer<Drawable>> objects;
};
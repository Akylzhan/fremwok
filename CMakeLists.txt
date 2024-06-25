cmake_minimum_required(VERSION 3.20)

project(fremwok LANGUAGES C CXX)
set(SDL_STATIC ON)
set(SDL_SHARED OFF)
set(SDL_TEST_LIBRARY OFF)
set(CORRADE_BUILD_STATIC ON)
set(MAGNUM_BUILD_STATIC ON)
set(MAGNUM_WITH_WGLCONTEXT ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
add_subdirectory(third_party)
find_package(Corrade REQUIRED COMPONENTS Containers)
find_package(Magnum REQUIRED COMPONENTS WglContext GL Shaders Trade)

add_executable(${PROJECT_NAME})
add_subdirectory(src)
add_subdirectory(assets)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

target_link_libraries(${PROJECT_NAME} PUBLIC
    SDL3::SDL3-static
    Corrade::Containers
    Magnum::Magnum
    Magnum::GL
    Magnum::GLContext
    Magnum::Shaders
    Magnum::Trade
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

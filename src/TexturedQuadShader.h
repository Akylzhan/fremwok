#pragma once

#include <Magnum/GL/AbstractShaderProgram.h>
#include <Magnum/Shaders/GenericGL.h>

#include <cstdint>

class TexturedQuadShader : Magnum::GL::AbstractShaderProgram
{
  public:
    explicit TexturedQuadShader();

  private:
    std::uint32_t colorUniform;
    std::uint32_t textureUnit = 0;
};
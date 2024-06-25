#pragma once

#include <Drawable.h>

#include <Magnum/GL/Texture.h>
#include <Magnum/GL/Mesh.h.>

class Texture : public Drawable
{
  public:
    Texture();
    ~Texture();
    void draw() override;

  private:
    Magnum::GL::Mesh mesh;
    Magnum::GL::Texture2D texture;
};
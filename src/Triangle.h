#pragma once
#include <Drawable.h>

#include <Magnum/GL/Mesh.h>
#include <Magnum/Shaders/VertexColorGL.h>

class Triangle : public Drawable
{
  public:
    Triangle();
    void draw() override;
    virtual ~Triangle();

  private:
    Magnum::GL::Mesh mesh;
    Magnum::Shaders::VertexColorGL2D shader;
};
#include <Texture.h>
#include <TexturedQuadShader.h>

#include <Magnum/GL/Mesh.h>
#include <Magnum/Math/Vector2.h>
#include "Magnum/Shaders/GenericGL.h"

using namespace Magnum;

Texture::Texture()
{
    struct QuadVertex {
        Magnum::Vector2 position;
        Magnum::Vector2 textureCoordinates;
    };

    QuadVertex const vertices[]{
        {{0.5f, -0.5f}, {1.0f, 0.0f}},  /* Bottom right */
        {{0.5f, 0.5f}, {1.0f, 1.0f}},   /* Top right */
        {{-0.5f, -0.5f}, {0.0f, 0.0f}}, /* Bottom left */
        {{-0.5f, 0.5f}, {0.0f, 1.0f}}   /* Top left */
    };

    mesh.setPrimitive(GL::MeshPrimitive::TriangleStrip)
        .setCount(Containers::arraySize(vertices))
        .addVertexBuffer(GL::Buffer{vertices}, 0, Shaders::GenericGL3D::Position{}, Shaders::GenericGL3D::TextureCoordinates{});
}

Texture::~Texture() = default;

void Texture::draw()
{
}
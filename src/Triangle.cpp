#include <Triangle.h>

#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Mesh.h>

using namespace Corrade;
using namespace Magnum;

namespace
{
    using namespace Magnum::Math::Literals::ColorLiterals;

    struct TriangleVertex {
        Magnum::Vector2 position;
        Magnum::Color4 color;
    };

    TriangleVertex const vertices[]{
        {{-0.5f, -0.5f}, 0xff0000ff_rgbaf}, /* Left vertex, red color */
        {{0.5f, -0.5f}, 0x00ff00ff_rgbaf},  /* Right vertex, green color */
        {{0.0f, 0.5f}, 0x0000ffff_rgbaf},   /* Top vertex, blue color */
        {{0.5f, 0.5f}, 0xff00ff00_rgbaf},
    };
    Magnum::UnsignedInt const indices[]{
        0,
        1,
        2,
        1,
        3,
        2,
    };
}  // namespace

Triangle::Triangle()
{
    mesh.setCount(Containers::arraySize(indices))
        .addVertexBuffer(GL::Buffer{vertices}, 0, Shaders::VertexColorGL2D::Position{}, Shaders::VertexColorGL2D::Color4{})
        .setIndexBuffer(GL::Buffer{indices}, 0, Magnum::MeshIndexType::UnsignedInt);
}

Triangle::~Triangle() = default;

void Triangle::draw()
{
    shader.draw(mesh);
}
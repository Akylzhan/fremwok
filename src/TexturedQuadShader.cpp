
#include <TexturedQuadShader.h>

#include <Corrade/Utility/Resource.h>
#include <Magnum/GL/Context.h>
#include <Magnum/GL/Shader.h>
#include <Magnum/GL/Version.h>
#include "Corrade/Utility/Format.h"

using namespace Magnum;

TexturedQuadShader::TexturedQuadShader()
{
    MAGNUM_ASSERT_GL_VERSION_SUPPORTED(GL::Version::GL330);

    GL::Shader vert{GL::Version::GL330, GL::Shader::Type::Vertex};
    GL::Shader frag{GL::Version::GL330, GL::Shader::Type::Fragment};

    Utility::Resource const rs{"texturedquad-data"};
    vert.addSource(Utility::format("#define POSITION_ATTRIBUTE_LOCATION {}\n"
                                   "#define NORMAL_ATTRIBUTE_LOCATION {}\n",
                                   Shaders::GenericGL3D::Position::Location,
                                   Shaders::GenericGL3D::Normal::Location))
        .addSource(rs.getString("TexturedQuadShader.vert"));
    frag.addSource(rs.getString("TexturedQuadShader.frag"));

    CORRADE_INTERNAL_ASSERT_OUTPUT(vert.compile() && frag.compile());
    attachShaders({vert, frag});
    CORRADE_INTERNAL_ASSERT_OUTPUT(link());

    colorUniform = uniformLocation("color");
    setUniform(uniformLocation("textureData"), textureUnit);
}
layout(location = POSITION_ATTRIBUTE_LOCATION) in vec4 position;
layout(location = TEXTURE_COORDINATES_ATTRIBUTE_LOCATION) in vec2 textCoords;

out vec2 interpolatedTextCoords;

void main() {
    interpolatedTextCoords = textCoords;
    gl_Position = position;
}
#version 330 core
layout (location = 0) in vec2 vertex; // <vec2 pos>

out vec4 drawColor;

uniform mat4 projection;
uniform vec4 inputColor;

void main()
{
    gl_Position = projection * vec4(vertex.xy, 0.0, 1.0);
    drawColor = inputColor;
}
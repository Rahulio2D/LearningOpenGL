#version 330 core

in vec3 outColour;
out vec4 FragColor;

void main()
{
    FragColor = vec4(outColour, 1.0f);
}
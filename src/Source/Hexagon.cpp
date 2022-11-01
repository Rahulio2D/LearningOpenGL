#include "Hexagon.h"
#include <GL/glew.h>
#include <iostream>
#include "Shader.h"
#include "VertexArray.h"
#include "BufferObject.h"

Hexagon::Hexagon()
{
    // 3 position and 3 colour attributes per line
    vertices = new float[NUM_VERTICES] {
        0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,     // Middle
        -0.2f, 0.7f, 0.0f, 1.0f, 0.0f, 0.0f,    // Top left
        -0.45f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,   // Left
        -0.2f, -0.7f, 0.0f, 0.0f, 0.0f, 1.0f,   // Bottom left
        0.2f, -0.7f, 0.0f, 1.0f, 1.0f, 0.0f,    // Bottom right
        0.45f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,    // Right
        0.2f, 0.7f, 0.0f, 0.0f, 1.0f, 1.0f,     // Top right
    };

    indices = new unsigned int[NUM_INDICES] {
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 4, 5,
        0, 5, 6,
        0, 6, 1
    };

    vertexArray = new VertexArray();
    vertexArray->Bind();

    vertexBuffer = new BufferObject(BufferType::ARRAY_BUFFER);
    vertexBuffer->Bind();
    vertexBuffer->SetData(sizeof(GL_FLOAT) * NUM_VERTICES, vertices, BufferUsage::STATIC_DRAW);

    indexBuffer = new BufferObject(BufferType::ELEMENT_ARRAY_BUFFER);
    indexBuffer->Bind();
    indexBuffer->SetData(sizeof(unsigned int) * NUM_INDICES, indices, BufferUsage::STATIC_DRAW);

    shader = new Shader();
    shader->AddShader(ShaderType::FRAGMENT, "Assets/Shaders/default_fragment.glsl");
    shader->AddShader(ShaderType::VERTEX, "Assets/Shaders/default_vertex.glsl");
    shader->Bind();

    vertexArray->SetVertexData(0, 3, DataType::FLOAT, Normalised::FALSE, 6 * sizeof(float), 0);
    vertexArray->SetVertexData(1, 3, DataType::FLOAT, Normalised::FALSE, 6 * sizeof(float), 3 * sizeof(float));
    vertexArray->EnableAttribute(0);
    vertexArray->EnableAttribute(1);
}

Hexagon::~Hexagon()
{
    delete shader;
    delete vertexArray;
    delete vertexBuffer;
    delete indexBuffer;
}

void Hexagon::Render()
{
    shader->Bind();
    vertexArray->Bind();

    glDrawElements(GL_TRIANGLES, NUM_INDICES, GL_UNSIGNED_INT, 0);
    
    shader->Unbind();
    vertexArray->Unbind();
}
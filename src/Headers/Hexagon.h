#ifndef HEXAGON_H
#define HEXAGON_H

class Shader;
class BufferObject;
class VertexArray;

class Hexagon
{
public:
    Hexagon();
    ~Hexagon();

    void Render();

private:
    #define NUM_VERTICES 42
    #define NUM_INDICES 18
    float* vertices;
    unsigned int* indices;

    Shader* shader;
    VertexArray* vertexArray;
    BufferObject* indexBuffer;
    BufferObject* vertexBuffer;
};

#endif
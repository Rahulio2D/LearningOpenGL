#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

enum Normalised { FALSE = 0, TRUE = 1 };
enum DataType { FLOAT = 0x1406 };

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();

    void Bind() const;
    void Unbind() const;

    void SetVertexData(unsigned int position, unsigned int size, DataType dataType, Normalised normalised, unsigned int stride, unsigned int offset);

    void EnableAttribute(unsigned int index) const;
    void DisableAttribute(unsigned int index) const;

private:
    unsigned int vertexArrayId;
};

#endif

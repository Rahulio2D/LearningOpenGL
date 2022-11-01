#include "VertexArray.h"
#include <GL/glew.h>

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &vertexArrayId);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &vertexArrayId);
}

void VertexArray::SetVertexData(unsigned int position, unsigned int size, DataType dataType, Normalised normalised, unsigned int stride, unsigned int offset)
{    
    glVertexAttribPointer(position, size, GLenum(dataType), GLenum(normalised), stride, (void*)offset);
}

void VertexArray::Bind() const
{
    glBindVertexArray(vertexArrayId);
}

void VertexArray::Unbind() const
{
    glBindVertexArray(0);
}

void VertexArray::EnableAttribute(unsigned int index) const
{
    glEnableVertexAttribArray(index);
}

void VertexArray::DisableAttribute(unsigned int index) const
{
    glDisableVertexAttribArray(index);
}
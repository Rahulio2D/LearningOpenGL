#include "BufferObject.h"
#include <GL/glew.h>

BufferObject::BufferObject(BufferType bufferType)
{
    this->bufferType = bufferType;
    glGenBuffers(1, &bufferId);
}

BufferObject::~BufferObject()
{
    glDeleteBuffers(1, &bufferId);
}

void BufferObject::SetData(unsigned int size, void* data, BufferUsage usage)
{
    Bind();
    glBufferData(GLenum(bufferType), size, data, GLenum(usage)); 
}

void BufferObject::Bind() const
{
    glBindBuffer(GLenum(bufferType), bufferId);
}

#ifndef BUFFER_OBJECT_H
#define BUFFER_OBJECT_H

enum BufferType { ARRAY_BUFFER = 0x8892, ELEMENT_ARRAY_BUFFER = 0x8893 };
enum BufferUsage { STATIC_DRAW = 0x88E4 };

class BufferObject
{
public:
    BufferObject(BufferType bufferType);
    ~BufferObject();

    void SetData(unsigned int size, void* data, BufferUsage usage);
    void Bind() const;

private:
    unsigned int bufferId;
    BufferType bufferType;
};

#endif
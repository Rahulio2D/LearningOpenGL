#ifndef SHADER_H
#define SHADER_H

#include <string>

enum ShaderType { FRAGMENT = 0x8B30, VERTEX = 0x8B31 };

class Shader
{
public:
    Shader();
    ~Shader();

    int AddShader(ShaderType shaderType, const char* shaderPath);

    void Bind() const;
    void Unbind() const;

private:
    int CompileShader(ShaderType shaderType, const char* shaderPath);
    int AttachShader(unsigned int shaderId);
    void GetShaderContents(const char* shaderPath, std::string& shaderContents);
    int GetShaderCompilationStatus(unsigned int shaderId, std::string& errorLog);

    std::string GetShaderTypeAsString(ShaderType shaderType);

    unsigned int shaderProgramId;
};

#endif
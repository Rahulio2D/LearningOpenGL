#include "Shader.h"
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <string>

Shader::Shader()
{
    shaderProgramId = glCreateProgram();
}

Shader::~Shader()
{
    glDeleteProgram(shaderProgramId);
}

int Shader::AddShader(ShaderType shaderType, const char* shaderPath)
{
    unsigned int shaderId = CompileShader(shaderType, shaderPath);
    if(shaderId == -1) return -1;

    if(AttachShader(shaderId) == -1) return -1;
    return shaderId;
}

void Shader::Bind() const
{
    glUseProgram(shaderProgramId);
}

void Shader::Unbind() const
{
    glUseProgram(0);
}

int Shader::CompileShader(ShaderType shaderType, const char* shaderPath)
{
    std::string fileContents;
    GetShaderContents(shaderPath, fileContents);
    const char* shaderSource = fileContents.c_str();
    unsigned int shaderId = glCreateShader(GLenum(shaderType));
    glShaderSource(shaderId, 1, &shaderSource, 0);
    glCompileShader(shaderId);

    std::string errorLog;
    if(GetShaderCompilationStatus(shaderId, errorLog) == -1)
    {
        std::cout << "ERROR::SHADER::" << GetShaderTypeAsString(shaderType) << "::COMPILATION_FAILED" << std::endl;
        std::cout << errorLog << std::endl;
        return -1;
    }

    return shaderId;
}

int Shader::AttachShader(unsigned int shaderId)
{
    glAttachShader(shaderProgramId, shaderId);
    glLinkProgram(shaderProgramId);

    std::string errorLog;
    if(GetShaderCompilationStatus(shaderProgramId, errorLog) == -1)
    {
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED" << std::endl;
        std::cout << errorLog << std::endl;
        return -1;
    }

    glDeleteShader(shaderId);
    return 0;
}

void Shader::GetShaderContents(const char* shaderPath, std::string& fileContents)
{
    std::string line;
    std::ifstream fileStream(shaderPath);
    while(std::getline(fileStream, line))
    {
        fileContents += line + "\n";
    }
}

int Shader::GetShaderCompilationStatus(unsigned int shaderId, std::string& errorLog)
{
    int success;
    char errorOutput[512];
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shaderId, 512, 0, errorOutput);
        errorLog = std::string(errorOutput);
        return -1;
    }
    return 0;
}

std::string Shader::GetShaderTypeAsString(ShaderType shaderType)
{
    switch(shaderType)
    {
        case FRAGMENT: return "FRAGMENT";
        case VERTEX: return "VERTEX";
        default: return "UNKNOWN";
    }
}

#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>; // ����glad����ȡ���еı���OpenGLͷ�ļ�

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	// ����һ��ID
	unsigned int ID;
	// ���캯��
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	// ʹ��/�������
	void use() { glUseProgram(ID); }
	// uniform���ߺ���
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;

private:
	// ������������Ƿ����
	void checkCompileErrors(unsigned int shader, std::string type);
};

#endif

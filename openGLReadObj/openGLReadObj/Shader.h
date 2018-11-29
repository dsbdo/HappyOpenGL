#pragma once
#ifndef SHADER_H
#define SHADER_H
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
class Shader {
public:
	unsigned int ID;
	//读取并构建着色器
	Shader(const GLchar* vertex_path, const GLchar* fragment_path) {
		//通过文件路径读取shader 程序
		using namespace::std;
		string vertex_src_code;
		string fragment_src_code;
		ifstream vertex_shader_file;
		ifstream fragment_shader_file;
		//保证ifstream 可以抛出异常
		vertex_shader_file.exceptions(ifstream::failbit | ifstream::badbit);
		fragment_shader_file.exceptions(ifstream::failbit | ifstream::badbit);
		try {
			vertex_shader_file.open(vertex_path);
			fragment_shader_file.open(fragment_path);
			stringstream vertex_stream, fragment_stream;
			vertex_stream << vertex_shader_file.rdbuf();
			fragment_stream << fragment_shader_file.rdbuf();
			//转换成string
			vertex_src_code = vertex_stream.str();
			fragment_src_code = fragment_stream.str();
		}
		catch (ifstream::failure e){
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		}
		const char* vertex_src_code_char = vertex_src_code.c_str();
		const char* fragment_src_code_char = fragment_src_code.c_str();

		//编译着色器
		unsigned int vertex_id, fragment_id;
		vertex_id = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex_id, 1, &vertex_src_code_char, NULL);
		glCompileShader(vertex_id);
		checkCompileErrors(vertex_id, "VERTEX");

		//片段着色器编译
		fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_id, 1, &fragment_src_code_char, NULL);
		glCompileShader(fragment_id);
		checkCompileErrors(fragment_id, "FRAGMENT");

		//链接程序
		ID = glCreateProgram();
		glAttachShader(ID, vertex_id);
		glAttachShader(ID, fragment_id);
		glLinkProgram(ID);
		checkCompileErrors(ID, "PROGRAM");

		//删除无用得shade程序
		glDeleteShader(vertex_id);
		glDeleteShader(fragment_id);

	}
	//使用着色器
	void use() {
		glUseProgram(ID);
	}
	//设置uniform 工具函数
	void setBool(const std::string& name, bool value) const {
		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
	}
	void setInt(const std::string& name, int value) const {
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}
	void setFloat(const std::string& name, float value) const {
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
	}
	void setVec2(const std::string &name, const glm::vec2 &value) const
	{
		glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
	}
	void setVec2(const std::string &name, float x, float y) const
	{
		glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
	}
	// ------------------------------------------------------------------------
	void setVec3(const std::string &name, const glm::vec3 &value) const
	{
		glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
	}
	void setVec3(const std::string &name, float x, float y, float z) const
	{
		glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
	}
	// ------------------------------------------------------------------------
	void setVec4(const std::string &name, const glm::vec4 &value) const
	{
		glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
	}
	void setVec4(const std::string &name, float x, float y, float z, float w)
	{
		glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
	}
	// ------------------------------------------------------------------------
	void setMat2(const std::string &name, const glm::mat2 &mat) const
	{
		glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}
	// ------------------------------------------------------------------------
	void setMat3(const std::string &name, const glm::mat3 &mat) const
	{
		glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}
	// ------------------------------------------------------------------------
	void setMat4(const std::string &name, const glm::mat4 &mat) const
	{
		glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}


private:
	void checkCompileErrors(unsigned int shader, std::string type)
	{
		int success;
		char infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
	}
};
#endif // !SHADER_H

#pragma once
#include <iostream>
#include<GL\glew.h>
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

void printShaderLog(GLuint shader);
void printProgramLog(GLuint prog);
bool checkOpenGLError();
string readShaderSource(const char* filePath);

GLuint createShaderProgram(const char* vp, const char* fp); //顶点着色器,片段着色器
GLuint createShaderProgram(const char* vp, const char* gp, const char* fp); //顶点着色器,几何着色器,片段着色器
GLuint createShaderProgram(const char* vp, const char* tCS, const char* tES,const char *fp); //加入曲面细分着色器tCS和tES
GLuint createShaderProgram(const char* vp, const char* tCS, const char* tES, const char* gp, const char* fp);

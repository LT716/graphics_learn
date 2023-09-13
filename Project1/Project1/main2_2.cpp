#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<iostream>
#include<string>
#include"Utils.h"

#define numVAOs 1

GLuint renderingProgram;
GLuint vao[numVAOs];

void init(GLFWwindow* window) {
	renderingProgram = createShaderProgram("vertShader.glsl", "fragShader.glsl");
	glGenVertexArrays(numVAOs, vao);
	glBindVertexArray(vao[0]);
}

GLfloat s = 30.0f;
GLfloat d = 0.1f;
void display2_2(GLFWwindow* window, double currentTime) {
	glUseProgram(renderingProgram); // 将已编译着色器程序载入OpenGL管线阶段(在GPU上!),此时还未运行着色器,只是加载进硬件.
	glClear(GL_COLOR_BUFFER_BIT);
	s = s + d;
	if (s >= 50.0f) d = -0.1f;
	if (s <= 10.0f) d = 0.1f;
	glPointSize(s);
	glDrawArrays(GL_POINTS, 0, 1); // 启动管线处理.
}


float x = 0.0f;
float inc = 0.01f;
void display2_6(GLFWwindow* window, double currentTime) {
	glClear(GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(renderingProgram);

	x += inc;
	if (x > 1.0f) inc = -0.01f;
	if (x < -1.0f) inc = 0.01f;
	GLuint offsetLoc = glGetUniformLocation(renderingProgram, "offset");
	glProgramUniform1f(renderingProgram, offsetLoc, x);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}


int main(void) {
	if (!glfwInit()) { exit(EXIT_FAILURE); }
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	GLFWwindow* window = glfwCreateWindow(600, 600, "Chapter2 - programl", NULL, NULL);
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); }
	glfwSwapInterval(1);  //开启垂直同步
	init(window);
	/*GLfloat size[] = {1.0f,2.0f,3.0f};
	glGetFloatv(GL_POINT_SIZE_RANGE, size);*/
	while (!glfwWindowShouldClose(window)) {
		display2_6(window, glfwGetTime());
		checkOpenGLError();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
/**
 * This project (GLSL_Project1) is created by Fahim Hasan Khan (fahimhasan.khan [at] ucalgary.ca)
 * based on the works of Andrew Robert Owens (arowens [at] ucalgary.ca)
 * who is a PhD student at Graphics Jungle, University of Calgary
 *
 * File:	main.cpp
 *
 * Summary:
 *
 * This is a (very) basic program to
 * 1) load shaders from external files, and make a shader program
 * 2) make Vertex Array Object and Vertex Buffer Object for the quad
 *
 **/
#include <cmath>
#include <iostream>


#include <chrono>
#include <limits>


#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "ShaderTools.h"
#include "Vec3f.h"
#include "Mat4f.h"
#include "OpenGLMatrixTools.h"
#include "Camera.h"

//==================== GLOBAL VARIABLES ====================//
/*	Put here for simplicity. Feel free to restructure into
*	appropriate classes or abstractions.
*/

// Drawing Program
GLuint basicProgramID;
GLuint basicProgramID1;

// Data needed for Quad
GLuint vaoID;
GLuint vertBufferID;
Mat4f M;

//Quad2

GLuint vaoID2;
GLuint vertBufferID2;
Mat4f M2;
//cube1
GLuint vaoID3;
GLuint vertBufferID3;
Mat4f M3;
//cube2
GLuint vaoID4;
GLuint vertBufferID4;
Mat4f M4;
//quad3
GLuint vaoID5;
GLuint vertBufferID5;
Mat4f M5;
//cube3
GLuint vaoID6;
GLuint vertBufferID6;
Mat4f M6;
//cube4
GLuint vaoID7;
GLuint vertBufferID7;
Mat4f M7;
//cube5
GLuint vaoID8;
GLuint vertBufferID8;
Mat4f M8;
//quad4
GLuint vaoID9;
GLuint vertBufferID9;
Mat4f M9;
//pyramid
GLuint p_vaoID;
GLuint p_vertBufferID;
Mat4f p_M;

//dandi_1
GLuint vaoID10;
GLuint vertBufferID10;
Mat4f M10;

//dandi_2
GLuint vaoID11;
GLuint vertBufferID11;
Mat4f M11;

//dandi_3


// Data needed for Line
GLuint line_vaoID;
GLuint line_vertBufferID;
Mat4f line_M;

// Only one camera so only one veiw and perspective matrix are needed.
Mat4f V;
Mat4f P;

// Only one thing is rendered at a time, so only need one MVP
// When drawing different objects, update M and MVP = M * V * P
Mat4f MVP;

// Camera and veiwing Stuff
Camera camera;
int g_moveUpDown = 0;
int g_moveLeftRight = 0;
int g_moveBackForward = 0;
int g_rotateLeftRight = 0;
int g_rotateUpDown = 0;
int g_rotateRoll = 0;
float g_rotationSpeed = 0.015625;
float g_panningSpeed = 0.25;
bool g_cursorLocked;
float g_cursorX, g_cursorY;

bool g_play = false;

int WIN_WIDTH = 800, WIN_HEIGHT = 600;
int FB_WIDTH = 800, FB_HEIGHT = 600;
float WIN_FOV = 60;
float WIN_NEAR = 0.01;
float WIN_FAR = 1000;

//==================== FUNCTION DECLARATIONS ====================//
void displayFunc();
void resizeFunc();
void init();
void generateIDs();
void deleteIDs();
void setupVAO();
void loadQuadGeometryToGPU();
void reloadProjectionMatrix();
void loadModelViewMatrix();
void setupModelViewProjectionTransform();

void windowSetSizeFunc();
void windowKeyFunc(GLFWwindow *window, int key, int scancode, int action,
                   int mods);
void windowMouseMotionFunc(GLFWwindow *window, double x, double y);
void windowSetSizeFunc(GLFWwindow *window, int width, int height);
void windowSetFramebufferSizeFunc(GLFWwindow *window, int width, int height);
void windowMouseButtonFunc(GLFWwindow *window, int button, int action,
                           int mods);
void windowMouseMotionFunc(GLFWwindow *window, double x, double y);
void windowKeyFunc(GLFWwindow *window, int key, int scancode, int action,
                   int mods);
void animateQuad(float t);
void animateQuad3(float t);
void animateQuad4(float t);
void animateQuad5(float t);
void animateQuad6(float t);
void animateQuad7(float t);
void p_animateQuad(float t);
void moveCamera();
void reloadMVPUniform(GLuint ProgramID);
void reloadColorUniform(float r, float g, float b, GLuint ProgramID);
std::string GL_ERROR();
int main(int, char **);

//==================== FUNCTION DEFINITIONS ====================//

void displayFunc() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Use our shader
  glUseProgram(basicProgramID);

  // ===== DRAW QUAD ====== //
  MVP = P * V * M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.1, 0.5, 0.1,basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(vaoID);
  // Draw Quads, start at vertex 0, draw 4 of them (for a quad)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 57);

  //Quad2_sky
  MVP = P * V * M2;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.5, 0.7, 0.8,basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(vaoID2);
  // Draw Quads, start at vertex 0, draw 4 of them (for a quad)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  glUseProgram(basicProgramID1);
  //cube1_stage
  MVP = P * V * M3;
  reloadMVPUniform(basicProgramID1);
  reloadColorUniform(0.0, 0.0, 0.0,basicProgramID1);


  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(vaoID3);
  // Draw Quads, start at vertex 0, draw 4 of them (for a quad)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
  glUseProgram(basicProgramID);
  //cube2_rod
  MVP = P * V * M4;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1, 0.7, 0,basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(vaoID4);
  // Draw Quads, start at vertex 0, draw 4 of them (for a quad)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
  reloadColorUniform(1, 0, 0, basicProgramID);
  glDrawArrays(GL_LINE_LOOP, 0, 36);
  //quad3
   MVP = P * V * M5;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.6, 0, 0,basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(vaoID5);
  // Draw Quads, start at vertex 0, draw 4 of them (for a quad)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  //pyramid
  MVP = P * V * p_M;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.6, 0, 0,basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(p_vaoID);
  // Draw Quads, start at vertex 0, draw 4 of them (for a quad)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 7);
  //quad4

//cube3

  MVP = P * V * M8;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1, 0.5, 0.2,basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(vaoID8);
  // Draw Quads, start at vertex 0, draw 4 of them (for a quad)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
  reloadColorUniform(1, 0, 0, basicProgramID);
  glDrawArrays(GL_LINE_LOOP, 0, 36);
  MVP = P * V * M7;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1, 0.5, 0.2,basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(vaoID7);
  // Draw Quads, start at vertex 0, draw 4 of them (for a quad)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
  reloadColorUniform(1, 0, 0, basicProgramID);
  glDrawArrays(GL_LINE_LOOP, 0, 36);
  MVP = P * V * M6;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1, 0.5, 0.2,basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(vaoID6);
  // Draw Quads, start at vertex 0, draw 4 of them (for a quad)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
reloadColorUniform(1, 0, 0, basicProgramID);
  glDrawArrays(GL_LINE_LOOP, 0, 36);
  //circle
  MVP = P * V * M9;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(1.0, 0.1, 0.1,basicProgramID);



  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(vaoID9);
  // Draw Quads, start at vertex 0, draw 4 of them (for a quad)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 30);
  //dandi_1
  MVP = P * V * M10;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.4, 0.1, 0.1,basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(vaoID10);
  // Draw Quads, start at vertex 0, draw 4 of them (for a quad)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);


  //dandi_2
  MVP = P * V * M11;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.4, 0.1, 0.1,basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(vaoID11);
  // Draw Quads, start at vertex 0, draw 4 of them (for a quad)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  //dandi_3
 /* MVP = P * V * M12;
  reloadMVPUniform(basicProgramID);
  reloadColorUniform(0.4, 0.1, 0.1,basicProgramID);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  glBindVertexArray(vaoID12);
  // Draw Quads, start at vertex 0, draw 4 of them (for a quad)
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);*/
  // ==== DRAW LINE ===== //
  // ==== DRAW LINE ===== //
  //MVP = P * V * line_M;
  //reloadMVPUniform();

  //reloadColorUniform(0, 1, 1);

  // Use VAO that holds buffer bindings
  // and attribute config of buffers
  //glBindVertexArray(line_vaoID);
  // Draw lines
  //glDrawArrays(GL_LINES, 0, 2);

}

void animateQuad(float t) {

  M = RotateAboutYMatrix(100 * t);

  float s = (std::sin(t) + 1.0f) / 2.f;
  float x = (1 - s) * (10) + s * (-10);

    M = TranslateMatrix(x, 0, 0) * M;



  setupModelViewProjectionTransform();
  reloadMVPUniform(basicProgramID);
}

void animateQuad3(float t) {
  M3 = RotateAboutYMatrix(100 * t);

  float s = (std::sin(t) + 1.f) / 2.f;
  float x = (1 - s) * (10) + s * (-10);

  M3 = TranslateMatrix(x, 0, 0) * M3;

  setupModelViewProjectionTransform();
  reloadMVPUniform(basicProgramID1);
}
void animateQuad4(float t) {
  M4 = RotateAboutYMatrix(100 * t);

  float s = (std::sin(t) + 1.f) / 2.f;
  float x = (1 - s) * (10) + s * (-10);

  M4 = TranslateMatrix(x, 0, 0) * M4;

  setupModelViewProjectionTransform();
  reloadMVPUniform(basicProgramID);
}

void p_animateQuad(float t) {
  p_M = RotateAboutYMatrix(100 * t);

  float s = (std::sin(t) + 1.f) / 2.f;
  float x = (1 - s) * (10) + s * (-10);

  p_M = TranslateMatrix(x, 0, 0) * p_M;

  setupModelViewProjectionTransform();
  reloadMVPUniform(basicProgramID);
}
void animateQuad5(float t) {
  M6 = RotateAboutYMatrix(100 * t);

  float s = (std::sin(t) + 1.f) / 2.f;
  float x = (1 - s) * (10) + s * (-10);

  M6 = TranslateMatrix(x, 0, 0) * M6;

  setupModelViewProjectionTransform();
  reloadMVPUniform(basicProgramID);
}
void animateQuad6(float t) {
  M7 = RotateAboutYMatrix(100 * t);

  float s = (std::sin(t) + 1.f) / 2.f;
  float x = (1 - s) * (10) + s * (-10);

  M7 = TranslateMatrix(x, 0, 0) * M7;

  setupModelViewProjectionTransform();
  reloadMVPUniform(basicProgramID);
}
void animateQuad7(float t) {
  M8 = RotateAboutYMatrix(100 * t);

  float s = (std::sin(t) + 1.f) / 2.f;
  float x = (1 - s) * (10) + s * (-10);

  M8 = TranslateMatrix(x, 0, 0) * M8;

  setupModelViewProjectionTransform();
  reloadMVPUniform(basicProgramID);
}
void animateQuad8(float t) {
  M9 = RotateAboutYMatrix(100 * t);

  float s = (std::sin(t) + 1.f) / 2.f;
  float x = (1 - s) * (10) + s * (-10);

  M9 = TranslateMatrix(x, 0, 0) * M9;

  setupModelViewProjectionTransform();
  reloadMVPUniform(basicProgramID);
}
void animateQuad9(float t) {

  M10 = RotateAboutYMatrix(100 * t);

  float s = (std::sin(t) + 1.0f) / 2.f;
  float x = (1 - s) * (10) + s * (-10);

    M10 = TranslateMatrix(x, 0, 0) * M10;



  setupModelViewProjectionTransform();
  reloadMVPUniform(basicProgramID);
}
void animateQuad10(float t) {

  M11 = RotateAboutYMatrix(100 * t);

  float s = (std::sin(t) + 1.0f) / 2.f;
  float x = (1 - s) * (10) + s * (-10);

    M11 = TranslateMatrix(x, 0, 0) * M11;



  setupModelViewProjectionTransform();
  reloadMVPUniform(basicProgramID);
}


//flag
void loadQuadGeometryToGPU() {
  // Just basic layout of floats, for a quad
  // 3 floats per vertex, 4 vertices
  //flag
  std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-2.75, 8.0, 0.0));
  verts.push_back(Vec3f(-2.5, 7.0, 0.0));
  verts.push_back(Vec3f(-1.95, 8.1, 0.0));

  verts.push_back(Vec3f(-1.95, 8.1, 0.0));
  verts.push_back(Vec3f(-2.5, 7.0, 0.0));
  verts.push_back(Vec3f(-2.25, 6.5, 0.0));

  verts.push_back(Vec3f(-2.25, 6.5, 0.0));
  verts.push_back(Vec3f(-1.95, 8.1, 0.0));
  verts.push_back(Vec3f(-2.25, 6.0, 0.0));

  verts.push_back(Vec3f(-2.25, 6.0, 0.0));
  verts.push_back(Vec3f(-1.95, 8.1, 0.0));
  verts.push_back(Vec3f(-1.95, 5.0, 0.0));

  verts.push_back(Vec3f(-1.95, 5.0, 0.0));
  verts.push_back(Vec3f(-2.25, 6.0, 0.0));
  verts.push_back(Vec3f(-2.5, 5.5, 0.0));

  verts.push_back(Vec3f(-2.5, 5.5, 0.0));
  verts.push_back(Vec3f(-2.75, 5.0, 0.0));
  verts.push_back(Vec3f(-1.95, 5.0, 0.0));




  verts.push_back(Vec3f(-1.95, 5.0, 0.0));
  verts.push_back(Vec3f(-1.95, 8.1, 0.0));
  verts.push_back(Vec3f(-1.15, 8.2, 0.0));

  verts.push_back(Vec3f(-1.15, 8.2, 0.0));
  verts.push_back(Vec3f(-1.95, 5.0, 0.0));
  verts.push_back(Vec3f(-1.15, 5.0, 0.0));

  verts.push_back(Vec3f(-1.15, 5.0, 0.0));
  verts.push_back(Vec3f(-1.15, 8.2, 0.0));
  verts.push_back(Vec3f(-0.35, 8.2, 0.0));

  verts.push_back(Vec3f(-0.35, 8.2, 0.0));
  verts.push_back(Vec3f(-1.15, 5.0, 0.0));
  verts.push_back(Vec3f(-0.35, 5.0, 0.0));

   verts.push_back(Vec3f(-0.35, 5.0, 0.0));
  verts.push_back(Vec3f(-0.35, 8.2, 0.0));
  verts.push_back(Vec3f(0.45, 8.1, 0.0));

   verts.push_back(Vec3f(0.45, 8.1, 0.0));
  verts.push_back(Vec3f(-0.35, 5.0, 0.0));
  verts.push_back(Vec3f(0.45, 5.0, 0.0));

   verts.push_back(Vec3f(0.45, 5.0, 0.0));
  verts.push_back(Vec3f(0.45, 8.1, 0.0));
  verts.push_back(Vec3f(1.25, 8.0, 0.0));

   verts.push_back(Vec3f(1.25, 8.0, 0.0));
  verts.push_back(Vec3f(0.45, 5.0, 0.0));
  verts.push_back(Vec3f(1.25, 5.0, 0.0));

   verts.push_back(Vec3f(1.25, 5.0, 0.0));
  verts.push_back(Vec3f(1.25, 8.0, 0.0));
  verts.push_back(Vec3f(2.25, 7.9, 0.0));

   verts.push_back(Vec3f(2.25, 7.9, 0.0));
  verts.push_back(Vec3f(1.25, 5.0, 0.0));
  verts.push_back(Vec3f(2.25, 5.25, 0.0));

   verts.push_back(Vec3f(2.25, 5.25, 0.0));
  verts.push_back(Vec3f(2.25, 7.9, 0.0));
  verts.push_back(Vec3f(3.25, 8.0, 0.0));

   verts.push_back(Vec3f(3.25, 8.0, 0.0));
  verts.push_back(Vec3f(2.25, 5.25, 0.0));
  verts.push_back(Vec3f(2.35, 5.75, 0.0));

   verts.push_back(Vec3f(2.35, 5.75, 0.0));
  verts.push_back(Vec3f(2.75, 5.5, 0.0));
  verts.push_back(Vec3f(2.25, 5.25, 0.0));


  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 57, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}
//circle
void loadQuad9GeometryToGPU() {
  // Just basic layout of floats, for a quad
  // 3 floats per vertex, 4 vertices
  std::vector<Vec3f> verts;


verts.push_back(Vec3f(0.05f, 7.3f, 0.25f));
verts.push_back(Vec3f(0.05f, 5.7f,0.25f));
verts.push_back(Vec3f(0.45f, 7.3f, 0.25f));

verts.push_back(Vec3f(0.45f, 7.3f, 0.25f));
verts.push_back(Vec3f(0.45f, 5.7f, 0.25f));
verts.push_back(Vec3f(0.05f,5.7f, 0.25f));

verts.push_back(Vec3f(0.05f, 5.7f, 0.25f));
verts.push_back(Vec3f(0.05f,7.3f, 0.25f));
verts.push_back(Vec3f(-0.35f,7.1f, 0.25f));

verts.push_back(Vec3f(-0.35f, 7.1f, 0.25f));
verts.push_back(Vec3f(0.05f, 5.7f,0.25f));
verts.push_back(Vec3f(-0.35f, 5.9f,0.25f));

verts.push_back(Vec3f(-0.35f, 5.9f, 0.25f));
verts.push_back(Vec3f(-0.35f, 7.1f,0.25f));
verts.push_back(Vec3f(-0.55f, 6.7f,0.25f));

verts.push_back(Vec3f(-0.55f, 6.7f, 0.25f));
verts.push_back(Vec3f(-0.35f, 5.9f,0.25f));
verts.push_back(Vec3f(-0.55f, 6.3f,0.25f));


verts.push_back(Vec3f(0.45f,7.3f,0.25f));
verts.push_back(Vec3f(0.45f, 5.7f, 0.25f));
verts.push_back(Vec3f(0.85f,7.1f, 0.25f));

verts.push_back(Vec3f(0.85f, 7.1f, 0.25f));
verts.push_back(Vec3f(0.45f, 5.7f,0.25f));
verts.push_back(Vec3f(0.85f, 5.9f,0.25f));

verts.push_back(Vec3f(0.85f, 5.9f, 0.25f));
verts.push_back(Vec3f(0.85f, 7.1f,0.25f));
verts.push_back(Vec3f(1.05f, 6.7f,0.25f));

verts.push_back(Vec3f(1.05f, 6.7f, 0.25f));
verts.push_back(Vec3f(1.05f, 6.3f,0.25f));
verts.push_back(Vec3f(0.85f, 5.9f,0.25f));


               glBindBuffer(GL_ARRAY_BUFFER, vertBufferID9);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 30, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);
}


void loadQuad2GeometryToGPU() {
  // Just basic layout of floats, for a quad
  // 3 floats per vertex, 4 vertices
  std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-31, -10, -10));
  verts.push_back(Vec3f(-31, 17, -10));
  verts.push_back(Vec3f(31, -10, -10));
  verts.push_back(Vec3f(31, 17, -10));

  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID2);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}

void loadQuad3GeometryToGPU() {
  // Just basic layout of floats, for a quad
  // 3 floats per vertex, 4 vertices
  std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-8.0f,-6.0f,-5.0f));
verts.push_back(Vec3f(-8.0f,-6.0f, 5.0f));
verts.push_back(Vec3f(-8.0f, -2.0f, 5.0f));
verts.push_back(Vec3f(8.0f,  -2.0f,-5.0f));
verts.push_back(Vec3f(-8.0f,-6.0f,-5.0f));
verts.push_back(Vec3f(-8.0f, -2.0f,-5.0f));
verts.push_back(Vec3f(8.0f,-6.0f, 5.0f));
verts.push_back(Vec3f(-8.0f,-6.0f,-5.0f));
verts.push_back(Vec3f(8.0f,-6.0f,-5.0f));
verts.push_back(Vec3f(8.0f, -2.0f,-5.0f));
verts.push_back(Vec3f(8.0f,-6.0f,-5.0f));
verts.push_back(Vec3f(-8.0f,-6.0f,-5.0f));
verts.push_back(Vec3f(-8.0f,-6.0f,-5.0f));
verts.push_back(Vec3f(-8.0f, -2.0f, 5.0f));
verts.push_back(Vec3f(-8.0f, -2.0f,-5.0f));
verts.push_back(Vec3f(8.0f,-6.0f, 5.0f));
verts.push_back(Vec3f(-8.0f,-6.0f, 5.0f));
verts.push_back(Vec3f(-8.0f,-6.0f,-5.0f));
verts.push_back(Vec3f(-8.0f, -2.0f, 5.0f));
verts.push_back(Vec3f(-8.0f,-6.0f, 5.0f));
verts.push_back(Vec3f(8.0f,-6.0f, 5.0f));
verts.push_back(Vec3f(8.0f, -2.0f, 5.0f));
verts.push_back(Vec3f(8.0f,-6.0f,-5.0f));
verts.push_back(Vec3f(8.0f, -2.0f,-5.0f));
verts.push_back(Vec3f(8.0f,-6.0f,-5.0f));
verts.push_back(Vec3f(8.0f, -2.0f, 5.0f));
verts.push_back(Vec3f(8.0f,-6.0f, 5.0f));
verts.push_back(Vec3f(8.0f, -2.0f, 5.0f));
verts.push_back(Vec3f(8.0f, -2.0f,-5.0f));
verts.push_back(Vec3f(-8.0f, -2.0f,-5.0f));
verts.push_back(Vec3f(8.0f, -2.0f, 5.0f));
verts.push_back(Vec3f(-8.0f, -2.0f,-5.0f));
verts.push_back(Vec3f(-8.0f, -2.0f, 5.0f));
verts.push_back(Vec3f(8.0f, -2.0f, 5.0f));
verts.push_back(Vec3f(-8.0f, -2.0f, 5.0f));
verts.push_back(Vec3f(8.0f,-6.0f, 5.0f));

  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID3);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}

void loadQuad4GeometryToGPU() {
  // Just basic layout of floats, for a quad
  // 3 floats per vertex, 4 vertices
  std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-3.5f,-4.0f,-1.0f));
verts.push_back(Vec3f(-3.5f,-4.0f, 1.0f));
verts.push_back(Vec3f(-3.5f, 8.0f, 1.0f));
verts.push_back(Vec3f(-3.0f,  8.0f,-1.0f));
verts.push_back(Vec3f(-3.5f,-4.0f,-1.0f));
verts.push_back(Vec3f(-3.5f, 8.0f,-1.0f));
verts.push_back(Vec3f(-3.0f,-4.0f, 1.0f));
verts.push_back(Vec3f(-3.5f,-4.0f,-1.0f));
verts.push_back(Vec3f(-3.0f,-4.0f,-1.0f));
verts.push_back(Vec3f(-3.0f, 4.0f,-1.0f));
verts.push_back(Vec3f(-3.0f,-4.0f,-1.0f));
verts.push_back(Vec3f(-3.5f,-4.0f,-1.0f));
verts.push_back(Vec3f(-3.5f,-4.0f,-1.0f));
verts.push_back(Vec3f(-3.5f, 8.0f, 1.0f));
verts.push_back(Vec3f(-3.5f, 8.0f,-1.0f));
verts.push_back(Vec3f(-3.0f,-4.0f, 1.0f));
verts.push_back(Vec3f(-3.5f,-4.0f, 1.0f));
verts.push_back(Vec3f(-3.5f,-4.0f,-1.0f));
verts.push_back(Vec3f(-3.5f, 8.0f, 1.0f));
verts.push_back(Vec3f(-3.5f,-4.0f, 1.0f));
verts.push_back(Vec3f(-3.0f,-4.0f, 1.0f));
verts.push_back(Vec3f(-3.0f, 8.0f, 1.0f));
verts.push_back(Vec3f(-3.0f,-4.0f,-1.0f));
verts.push_back(Vec3f(-3.0f, 8.0f,-1.0f));
verts.push_back(Vec3f(-3.0f,-4.0f,-1.0f));
verts.push_back(Vec3f(-3.0f, 8.0f, 1.0f));
verts.push_back(Vec3f(-3.0f,-4.0f, 1.0f));
verts.push_back(Vec3f(-3.0f, 8.0f, 1.0f));
verts.push_back(Vec3f(-3.0f, 8.0f,-1.0f));
verts.push_back(Vec3f(-3.0f, 8.0f,-1.0f));
verts.push_back(Vec3f(-3.0f, 8.0f, 1.0f));
verts.push_back(Vec3f(-3.5f, 8.0f,-1.0f));
verts.push_back(Vec3f(-3.5f, 8.0f, 1.0f));
verts.push_back(Vec3f(-3.0f, 8.0f, 1.0f));
verts.push_back(Vec3f(-3.5f, 8.0f, 1.0f));
verts.push_back(Vec3f(-3.0f,-4.0f, 1.0f));

  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID4);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}
//quad3
void loadQuad5GeometryToGPU() {
  // Just basic layout of floats, for a quad
  // 3 floats per vertex, 4 vertices
  std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-31, -17, -10));
  verts.push_back(Vec3f(-31, -10, -10));
  verts.push_back(Vec3f(31, -17, -10));
  verts.push_back(Vec3f(31, -10, -10));

  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID5);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}

void loadQuad6GeometryToGPU() {
  // Just basic layout of floats, for a quad
  // 3 floats per vertex, 4 vertices
  std::vector<Vec3f> verts;
   verts.push_back(Vec3f(-3.0f,-6.0f,5.0f));
verts.push_back(Vec3f(-3.0f,-6.0f, 8.0f));
verts.push_back(Vec3f(-3.0f, -5.0f, 8.0f));
verts.push_back(Vec3f(3.0f,  -5.0f,5.0f));
verts.push_back(Vec3f(-3.0f,-6.0f,5.0f));
verts.push_back(Vec3f(-3.0f, -5.0f,5.0f));
verts.push_back(Vec3f(3.0f,-6.0f, 8.0f));
verts.push_back(Vec3f(-3.0f,-6.0f,5.0f));
verts.push_back(Vec3f(3.0f,-6.0f,5.0f));
verts.push_back(Vec3f(3.0f, -5.0f,5.0f));
verts.push_back(Vec3f(3.0f,-6.0f,5.0f));
verts.push_back(Vec3f(-3.0f,-6.0f,5.0f));
verts.push_back(Vec3f(-3.0f,-5.0f,5.0f));
verts.push_back(Vec3f(-3.0f, -5.0f, 8.0f));
verts.push_back(Vec3f(-3.0f, -5.0f,5.0f));
verts.push_back(Vec3f(3.0f,-6.0f, 8.0f));
verts.push_back(Vec3f(-3.0f,-6.0f, 8.0f));
verts.push_back(Vec3f(-3.0f,-6.0f,5.0f));
verts.push_back(Vec3f(-3.0f, -5.0f, 8.0f));
verts.push_back(Vec3f(-3.0f,-6.0f, 8.0f));
verts.push_back(Vec3f(3.0f,-6.0f, 8.0f));
verts.push_back(Vec3f(3.0f, -5.0f, 8.0f));
verts.push_back(Vec3f(3.0f,-6.0f,5.0f));
verts.push_back(Vec3f(3.0f, -5.0f,5.0f));
verts.push_back(Vec3f(3.0f,-6.0f,5.0f));
verts.push_back(Vec3f(3.0f, -5.0f, 8.0f));
verts.push_back(Vec3f(3.0f,-6.0f, 8.0f));
verts.push_back(Vec3f(3.0f, -5.0f, 8.0f));
verts.push_back(Vec3f(3.0f, -5.0f,5.0f));
verts.push_back(Vec3f(-3.0f, -5.0f,5.0f));
verts.push_back(Vec3f(3.0f, -5.0f, 8.0f));
verts.push_back(Vec3f(-3.0f, -5.0f,5.0f));
verts.push_back(Vec3f(-3.0f, -5.0f, 8.0f));
verts.push_back(Vec3f(3.0f, -5.0f, 8.0f));
verts.push_back(Vec3f(-3.0f, -5.0f, 8.0f));
verts.push_back(Vec3f(3.0f,-6.0f, 8.0f));


  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID6);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}

void loadQuad7GeometryToGPU() {
  // Just basic layout of floats, for a quad
  // 3 floats per vertex, 4 vertices
  std::vector<Vec3f> verts;
   verts.push_back(Vec3f(-2.0f,-5.0f,5.0f));
verts.push_back(Vec3f(-2.0f,-5.0f, 7.0f));
verts.push_back(Vec3f(-2.0f, -4.0f, 7.0f));
verts.push_back(Vec3f(2.0f,  -4.0f,5.0f));
verts.push_back(Vec3f(-2.0f,-5.0f,5.0f));
verts.push_back(Vec3f(-2.0f, -4.0f,5.0f));
verts.push_back(Vec3f(2.0f,-5.0f, 7.0f));
verts.push_back(Vec3f(-2.0f,-4.0f,5.0f));
verts.push_back(Vec3f(2.0f,-5.0f,5.0f));
verts.push_back(Vec3f(2.0f, -4.0f,5.0f));
verts.push_back(Vec3f(2.0f,-5.0f,5.0f));
verts.push_back(Vec3f(-2.0f,-5.0f,5.0f));
verts.push_back(Vec3f(-2.0f,-4.0f,5.0f));
verts.push_back(Vec3f(-2.0f, -4.0f, 7.0f));
verts.push_back(Vec3f(-2.0f, -4.0f,5.0f));
verts.push_back(Vec3f(2.0f,-5.0f, 7.0f));
verts.push_back(Vec3f(-2.0f,-5.0f, 7.0f));
verts.push_back(Vec3f(-2.0f,-5.0f,5.0f));
verts.push_back(Vec3f(-2.0f, -5.0f, 7.0f));
verts.push_back(Vec3f(-2.0f,-5.0f, 7.0f));
verts.push_back(Vec3f(2.0f,-5.0f, 7.0f));
verts.push_back(Vec3f(2.0f, -4.0f, 7.0f));
verts.push_back(Vec3f(2.0f,-5.0f,5.0f));
verts.push_back(Vec3f(2.0f, -4.0f,5.0f));
verts.push_back(Vec3f(2.0f,-5.0f,5.0f));
verts.push_back(Vec3f(2.0f, -4.0f, 7.0f));
verts.push_back(Vec3f(2.0f,-5.0f, 7.0f));
verts.push_back(Vec3f(2.0f, -4.0f, 7.0f));
verts.push_back(Vec3f(2.0f, -4.0f,5.0f));
verts.push_back(Vec3f(-2.0f, -4.0f,5.0f));
verts.push_back(Vec3f(2.0f, -4.0f, 7.0f));
verts.push_back(Vec3f(-2.0f, -4.0f,5.0f));
verts.push_back(Vec3f(-2.0f, -4.0f, 7.0f));
verts.push_back(Vec3f(2.0f, -4.0f, 7.0f));
verts.push_back(Vec3f(-2.0f, -4.0f, 7.0f));
verts.push_back(Vec3f(2.0f,-5.0f, 7.0f));


  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID7);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}
void loadQuad8GeometryToGPU() {
  // Just basic layout of floats, for a quad
  // 3 floats per vertex, 4 vertices
  std::vector<Vec3f> verts;
   verts.push_back(Vec3f(-1.0f,-4.0f,5.0f));
verts.push_back(Vec3f(-1.0f,-4.0f, 6.0f));
verts.push_back(Vec3f(-1.0f, -3.0f, 6.0f));
verts.push_back(Vec3f(1.0f,  -3.0f,6.0f));
verts.push_back(Vec3f(-1.0f,-4.0f,6.0f));
verts.push_back(Vec3f(-1.0f, -3.0f,5.0f));
verts.push_back(Vec3f(1.0f,-4.0f, 6.0f));
verts.push_back(Vec3f(-1.0f,-3.0f,5.0f));
verts.push_back(Vec3f(1.0f,-4.0f,5.0f));
verts.push_back(Vec3f(1.0f, -3.0f,5.0f));
verts.push_back(Vec3f(1.0f,-4.0f,5.0f));
verts.push_back(Vec3f(-1.0f,-3.0f,5.0f));
verts.push_back(Vec3f(-1.0f,-3.0f,5.0f));
verts.push_back(Vec3f(-1.0f, -3.0f, 6.0f));
verts.push_back(Vec3f(-1.0f, -3.0f,5.0f));
verts.push_back(Vec3f(1.0f,-4.0f, 6.0f));
verts.push_back(Vec3f(-1.0f,-4.0f, 6.0f));
verts.push_back(Vec3f(-1.0f,-4.0f,5.0f));
verts.push_back(Vec3f(-1.0f, -4.0f, 6.0f));
verts.push_back(Vec3f(-1.0f,-4.0f, 6.0f));
verts.push_back(Vec3f(1.0f,-4.0f, 6.0f));
verts.push_back(Vec3f(1.0f, -3.0f, 6.0f));
verts.push_back(Vec3f(1.0f,-4.0f,5.0f));
verts.push_back(Vec3f(1.0f, -3.0f,5.0f));
verts.push_back(Vec3f(1.0f,-4.0f,5.0f));
verts.push_back(Vec3f(1.0f, -3.0f, 6.0f));
verts.push_back(Vec3f(1.0f,-4.0f, 6.0f));
verts.push_back(Vec3f(1.0f, -3.0f, 6.0f));
verts.push_back(Vec3f(1.0f, -3.0f,5.0f));
verts.push_back(Vec3f(-1.0f, -3.0f,5.0f));
verts.push_back(Vec3f(1.0f, -3.0f, 6.0f));
verts.push_back(Vec3f(-1.0f, -3.0f,5.0f));
verts.push_back(Vec3f(-1.0f, -3.0f, 6.0f));
verts.push_back(Vec3f(1.0f, -3.0f, 6.0f));
verts.push_back(Vec3f(-1.0f, -3.0f, 6.0f));
verts.push_back(Vec3f(1.0f,-4.0f, 6.0f));


  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID8);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 36, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}

void p_loadQuadGeometryToGPU() {
  // Just basic layout of floats, for a quad
  // 3 floats per vertex, 4 vertices
  std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-5.5,-2,1));
  verts.push_back(Vec3f(-1,-2,1));
  verts.push_back(Vec3f(-3.225,0.0,0));
  verts.push_back(Vec3f(-1,-2,-1));
  verts.push_back(Vec3f(-5.5,-2,-1));
  verts.push_back(Vec3f(-1,-2,1));
  verts.push_back(Vec3f(-3.225,0.0,0));

  glBindBuffer(GL_ARRAY_BUFFER, p_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 7, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}

void loadQuad10GeometryToGPU() {
  // Just basic layout of floats, for a quad
  // 3 floats per vertex, 4 vertices
  std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-4.0, 7.85, 0.0));
  verts.push_back(Vec3f(-4.0, 8.0, 0.0));
  verts.push_back(Vec3f(-2.70, 7.85, 0.0));
  verts.push_back(Vec3f(-2.75, 8.0, 0.0));

  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID10);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}
void loadQuad11GeometryToGPU() {
  // Just basic layout of floats, for a quad
  // 3 floats per vertex, 4 vertices
  std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-4.0, 5.0, 0.0));
  verts.push_back(Vec3f(-4.0, 5.15, 0.0));
  verts.push_back(Vec3f(-2.75, 5.0, 0.0));
  verts.push_back(Vec3f(-2.70, 5.15, 0.0));
  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID11);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 4, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}


void loadLineGeometryToGPU() {
  // Just basic layout of floats, for a quad
  // 3 floats per vertex, 4 vertices
  std::vector<Vec3f> verts;
  verts.push_back(Vec3f(-10, 0, 0));
  verts.push_back(Vec3f(10, 0, 0));

  glBindBuffer(GL_ARRAY_BUFFER, line_vertBufferID);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(Vec3f) * 2, // byte size of Vec3f, 4 of them
               verts.data(),      // pointer (Vec3f*) to contents of verts
               GL_STATIC_DRAW);   // Usage pattern of GPU buffer
}

void setupVAO() {
  glBindVertexArray(vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
glBindVertexArray(vaoID2);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID2);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

glBindVertexArray(vaoID3);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID3);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
glBindVertexArray(vaoID4);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID4);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
 glBindVertexArray(vaoID5);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID5);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
glBindVertexArray(p_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, p_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
glBindVertexArray(vaoID6);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID6);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
glBindVertexArray(vaoID7);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID7);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
    glBindVertexArray(vaoID8);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID8);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
glBindVertexArray(vaoID9);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID9);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
glBindVertexArray(vaoID10);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID10);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );
    glBindVertexArray(vaoID11);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, vertBufferID11);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

  glBindVertexArray(line_vaoID);

  glEnableVertexAttribArray(0); // match layout # in shader
  glBindBuffer(GL_ARRAY_BUFFER, line_vertBufferID);
  glVertexAttribPointer(0,        // attribute layout # above
                        3,        // # of components (ie XYZ )
                        GL_FLOAT, // type of components
                        GL_FALSE, // need to be normalized?
                        0,        // stride
                        (void *)0 // array buffer offset
                        );

  glBindVertexArray(0); // reset to default
}

void reloadProjectionMatrix() {
  // Perspective Only

  // field of view angle 60 degrees
  // window aspect ratio
  // near Z plane > 0
  // far Z plane

  P = PerspectiveProjection(WIN_FOV, // FOV
                            static_cast<float>(WIN_WIDTH) /
                                WIN_HEIGHT, // Aspect
                            WIN_NEAR,       // near plane
                            WIN_FAR);       // far plane depth
}

void loadModelViewMatrix() {
  M = IdentityMatrix();
  M2=IdentityMatrix();
  M3=IdentityMatrix();
  M4=IdentityMatrix();
  M5=IdentityMatrix();
  M6=IdentityMatrix();
   M7=IdentityMatrix();
M8=IdentityMatrix();
M9=IdentityMatrix();
M10=IdentityMatrix();
M11=IdentityMatrix();
//M12=IdentityMatrix();
  p_M=IdentityMatrix();
  line_M = IdentityMatrix();
  // view doesn't change, but if it did you would use this
  V = camera.lookatMatrix();
}

void reloadViewMatrix() { V = camera.lookatMatrix(); }

void setupModelViewProjectionTransform() {
  MVP = P * V * M; // transforms vertices from right to left (odd huh?)
}

void reloadMVPUniform(GLuint ProgramID) {
  GLint id = glGetUniformLocation(ProgramID, "MVP");

  glUseProgram(ProgramID);
  glUniformMatrix4fv(id,        // ID
                     1,         // only 1 matrix
                     GL_TRUE,   // transpose matrix, Mat4f is row major
                     MVP.data() // pointer to data in Mat4f
                     );
}

void reloadColorUniform(float r, float g, float b, GLuint ProgramID) {
  GLint id = glGetUniformLocation(ProgramID, "inputColor");

  glUseProgram(ProgramID);
  glUniform3f(id, // ID in basic_vs.glsl
              r, g, b);
}

void generateIDs() {
  // shader ID from OpenGL
  std::string vsSource = loadShaderStringfromFile("./shaders/basic.vert");
  std::string fsSource = loadShaderStringfromFile("./shaders/basic.frag");
  basicProgramID = CreateShaderProgram(vsSource, fsSource);

  std::string vsSource1 = loadShaderStringfromFile("./shaders/cube.vert");
  std::string fsSource1 = loadShaderStringfromFile("./shaders/cube.frag");
  basicProgramID1 = CreateShaderProgram(vsSource1, fsSource1);

  // VAO and buffer IDs given from OpenGL
  glGenVertexArrays(1, &vaoID);
  glGenBuffers(1, &vertBufferID);
  glGenVertexArrays(1, &vaoID2);
  glGenBuffers(1, &vertBufferID2);
  glGenVertexArrays(1, &vaoID3);
  glGenBuffers(1, &vertBufferID3);
  glGenVertexArrays(1, &vaoID4);
  glGenBuffers(1, &vertBufferID4);
   glGenVertexArrays(1, &vaoID5);
  glGenBuffers(1, &vertBufferID5);
  glGenVertexArrays(1, &vaoID6);
  glGenBuffers(1, &vertBufferID6);
  glGenVertexArrays(1, &vaoID7);
  glGenBuffers(1, &vertBufferID7);
  glGenVertexArrays(1, &vaoID8);
  glGenBuffers(1, &vertBufferID8);
  glGenVertexArrays(1, &vaoID9);
  glGenBuffers(1, &vertBufferID9);
  glGenVertexArrays(1, &vaoID10);
  glGenBuffers(1, &vertBufferID10);
  glGenVertexArrays(1, &vaoID11);
  glGenBuffers(1, &vertBufferID11);
  glGenVertexArrays(1, &p_vaoID);
  glGenBuffers(1, &p_vertBufferID);
  glGenVertexArrays(1, &line_vaoID);
  glGenBuffers(1, &line_vertBufferID);
}

void deleteIDs() {
  glDeleteProgram(basicProgramID);
 glDeleteProgram(basicProgramID1);

  glDeleteVertexArrays(1, &vaoID);
  glDeleteBuffers(1, &vertBufferID);
  glDeleteVertexArrays(1, &vaoID2);
  glDeleteBuffers(1, &vertBufferID2);
  glDeleteVertexArrays(1, &vaoID3);
  glDeleteBuffers(1, &vertBufferID3);
  glDeleteVertexArrays(1, &vaoID4);
  glDeleteBuffers(1, &vertBufferID4);
  glDeleteVertexArrays(1, &vaoID5);
  glDeleteBuffers(1, &vertBufferID5);
  glDeleteVertexArrays(1, &vaoID6);
  glDeleteBuffers(1, &vertBufferID6);
  glDeleteVertexArrays(1, &vaoID7);
  glDeleteBuffers(1, &vertBufferID7);
  glDeleteVertexArrays(1, &vaoID8);
  glDeleteBuffers(1, &vertBufferID8);
  glDeleteVertexArrays(1, &vaoID9);
  glDeleteBuffers(1, &vertBufferID9);
  glDeleteVertexArrays(1, &vaoID10);
  glDeleteBuffers(1, &vertBufferID10);
  glDeleteVertexArrays(1, &vaoID11);
  glDeleteBuffers(1, &vertBufferID11);
  glDeleteVertexArrays(1, &p_vaoID);
  glDeleteBuffers(1, &p_vertBufferID);
  glDeleteVertexArrays(1, &line_vaoID);
  glDeleteBuffers(1, &line_vertBufferID);
}

void init() {
  glEnable(GL_DEPTH_TEST);
  glPointSize(50);

  camera = Camera(Vec3f{0, 0, 20}, Vec3f{0, 0, -1}, Vec3f{0, 1, 0});

  // SETUP SHADERS, BUFFERS, VAOs

  generateIDs();
  setupVAO();
  loadQuadGeometryToGPU();
  loadQuad2GeometryToGPU();
  loadQuad3GeometryToGPU();
  loadQuad4GeometryToGPU();
  loadQuad5GeometryToGPU();
  loadQuad6GeometryToGPU();
  loadQuad7GeometryToGPU();
  loadQuad8GeometryToGPU();
  loadQuad9GeometryToGPU();
  loadQuad10GeometryToGPU();
  loadQuad11GeometryToGPU();
  p_loadQuadGeometryToGPU();
  loadLineGeometryToGPU();

  loadModelViewMatrix();
  reloadProjectionMatrix();
  setupModelViewProjectionTransform();
  reloadMVPUniform(basicProgramID);
}

int main(int argc, char **argv) {
  GLFWwindow *window;

  if (!glfwInit()) {
    exit(EXIT_FAILURE);
  }

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window =
      glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "CSE414 Project 1", NULL, NULL);
  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  glfwSetWindowSizeCallback(window, windowSetSizeFunc);
  glfwSetFramebufferSizeCallback(window, windowSetFramebufferSizeFunc);
  glfwSetKeyCallback(window, windowKeyFunc);
  glfwSetCursorPosCallback(window, windowMouseMotionFunc);
  glfwSetMouseButtonCallback(window, windowMouseButtonFunc);

  glfwGetFramebufferSize(window, &WIN_WIDTH, &WIN_HEIGHT);

  // Initialize glad
  if (!gladLoadGL()) {
    std::cerr << "Failed to initialise GLAD" << std::endl;
    return -1;
  }

  std::cout << "GL Version: :" << glGetString(GL_VERSION) << std::endl;
  std::cout << GL_ERROR() << std::endl;

  // Initialize all the geometry, and load it once to the GPU
  init(); // our own initialize stuff func

  float t = 0;
  float dt = 0.01;

  while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
         !glfwWindowShouldClose(window)) {

    if (g_play) {
      t += dt;

      animateQuad(t);
      animateQuad3(t);
      animateQuad4(t);
      animateQuad5(t);
      animateQuad6(t);
      animateQuad7(t);
      animateQuad8(t);
      animateQuad9(t);
      animateQuad10(t);
      p_animateQuad(t);
    }

    displayFunc();
    moveCamera();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // clean up after loop
  deleteIDs();

  return 0;
}

//==================== CALLBACK FUNCTIONS ====================//

void windowSetSizeFunc(GLFWwindow *window, int width, int height) {
  WIN_WIDTH = width;
  WIN_HEIGHT = height;

  reloadProjectionMatrix();
  setupModelViewProjectionTransform();
  reloadMVPUniform(basicProgramID);
}

void windowSetFramebufferSizeFunc(GLFWwindow *window, int width, int height) {
  FB_WIDTH = width;
  FB_HEIGHT = height;

  glViewport(0, 0, FB_WIDTH, FB_HEIGHT);
}

void windowMouseButtonFunc(GLFWwindow *window, int button, int action,
                           int mods) {
  if (button == GLFW_MOUSE_BUTTON_LEFT) {
    if (action == GLFW_PRESS) {
      g_cursorLocked = GL_TRUE;
    } else {
      g_cursorLocked = GL_FALSE;
    }
  }
}

void windowMouseMotionFunc(GLFWwindow *window, double x, double y) {
  if (g_cursorLocked) {
    float deltaX = (x - g_cursorX) * 0.01;
    float deltaY = (y - g_cursorY) * 0.01;
    camera.rotateAroundFocus(deltaX, deltaY);

    reloadViewMatrix();
    setupModelViewProjectionTransform();
    reloadMVPUniform(basicProgramID);
  }

  g_cursorX = x;
  g_cursorY = y;
}

void windowKeyFunc(GLFWwindow *window, int key, int scancode, int action,
                   int mods) {
  bool set = action != GLFW_RELEASE && GLFW_REPEAT;
  switch (key) {
  case GLFW_KEY_ESCAPE:
    glfwSetWindowShouldClose(window, GL_TRUE);
    break;
  case GLFW_KEY_W:
    g_moveBackForward = set ? 1 : 0;
    break;
  case GLFW_KEY_S:
    g_moveBackForward = set ? -1 : 0;
    break;
  case GLFW_KEY_A:
    g_moveLeftRight = set ? 1 : 0;
    break;
  case GLFW_KEY_D:
    g_moveLeftRight = set ? -1 : 0;
    break;
  case GLFW_KEY_Q:
    g_moveUpDown = set ? -1 : 0;
    break;
  case GLFW_KEY_E:
    g_moveUpDown = set ? 1 : 0;
    break;
  case GLFW_KEY_UP:
    g_rotateUpDown = set ? -1 : 0;
    break;
  case GLFW_KEY_DOWN:
    g_rotateUpDown = set ? 1 : 0;
    break;
  case GLFW_KEY_LEFT:
    if (mods == GLFW_MOD_SHIFT)
      g_rotateRoll = set ? -1 : 0;
    else
      g_rotateLeftRight = set ? 1 : 0;
    break;
  case GLFW_KEY_RIGHT:
    if (mods == GLFW_MOD_SHIFT)
      g_rotateRoll = set ? 1 : 0;
    else
      g_rotateLeftRight = set ? -1 : 0;
    break;
  case GLFW_KEY_SPACE:
    g_play = set ? !g_play : g_play;
    break;
  case GLFW_KEY_LEFT_BRACKET:
    if (mods == GLFW_MOD_SHIFT) {
      g_rotationSpeed *= 0.5;
    } else {
      g_panningSpeed *= 0.5;
    }
    break;
  case GLFW_KEY_RIGHT_BRACKET:
    if (mods == GLFW_MOD_SHIFT) {
      g_rotationSpeed *= 1.5;
    } else {
      g_panningSpeed *= 1.5;
    }
    break;
  default:
    break;
  }
}

//==================== OPENGL HELPER FUNCTIONS ====================//

void moveCamera() {
  Vec3f dir;

  if (g_moveBackForward) {
    dir += Vec3f(0, 0, g_moveBackForward * g_panningSpeed);
  }
  if (g_moveLeftRight) {
    dir += Vec3f(g_moveLeftRight * g_panningSpeed, 0, 0);
  }
  if (g_moveUpDown) {
    dir += Vec3f(0, g_moveUpDown * g_panningSpeed, 0);
  }

  if (g_rotateUpDown) {
    camera.rotateUpDown(g_rotateUpDown * g_rotationSpeed);
  }
  if (g_rotateLeftRight) {
    camera.rotateLeftRight(g_rotateLeftRight * g_rotationSpeed);
  }
  if (g_rotateRoll) {
    camera.rotateRoll(g_rotateRoll * g_rotationSpeed);
  }

  if (g_moveUpDown || g_moveLeftRight || g_moveBackForward ||
      g_rotateLeftRight || g_rotateUpDown || g_rotateRoll) {
    camera.move(dir);
    reloadViewMatrix();
    setupModelViewProjectionTransform();
    reloadMVPUniform(basicProgramID);
  }
}

std::string GL_ERROR() {
  GLenum code = glGetError();

  switch (code) {
  case GL_NO_ERROR:
    return "GL_NO_ERROR";
  case GL_INVALID_ENUM:
    return "GL_INVALID_ENUM";
  case GL_INVALID_VALUE:
    return "GL_INVALID_VALUE";
  case GL_INVALID_OPERATION:
    return "GL_INVALID_OPERATION";
  case GL_INVALID_FRAMEBUFFER_OPERATION:
    return "GL_INVALID_FRAMEBUFFER_OPERATION";
  case GL_OUT_OF_MEMORY:
    return "GL_OUT_OF_MEMORY";
  default:
    return "Non Valid Error Code";
  }
}

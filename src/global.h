#pragma once

//#include <GLFW/glfw3.h>

#include "stb_image.h"

//#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
//#include <vector>

using namespace std;

// settings
extern const unsigned int SCR_WIDTH;
extern const unsigned int SCR_HEIGHT;

extern const char* const SAMPLE_NAME;

extern const vector<string> skyboxFaces;

//extern unsigned int TextureFromFile(const char* path, const string& directory, bool gamma = false);
//extern unsigned int createConstantTexture(const unsigned char* color, bool gamma);
extern unsigned int loadTexture(char const* path);
extern unsigned int loadCubemap(vector<std::string> faces);
extern void displayFps(unsigned int frame_count, GLFWwindow* window);

extern const float FPS_UPDATE_INTERVAL;
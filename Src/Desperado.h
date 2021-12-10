
#pragma once

#include "Core/Framework.h"
#define _USE_MATH_DEFINES
#include <math.h>

// GL
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Image
//#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "global.h"
#include "shader.h"
#include "scene.h"
#include "camera.h"
#include "light.h"
#include "model.h"

// Optix
#include <optixu/optixpp_namespace.h>
#include <optixu/optixu_math_namespace.h> 
#include <optixu/optixu_math_stream_namespace.h>

#include "optixUtil.h"
#include "optixMesh.h"
#include "optixLight.h"
#include "optixContext.h"


// Core/API
#include "Core/API/FBO.h"
#include "Core/API/Texture.h"


// RenderPass
#include "Passes/RenderPass.h"
#include "Passes/FullScreenPass.h"
#include "Passes/SVGFPass.h"

// Scene
//#include "Scene/Scene.h"

// Utils
#include "Utils/Math/Vector.h"
#include "Utils/InternalDictionary.h"
#include "Utils/Threading.h"


#define DESPERADO_MAJOR_VERSION 1
#define DESPERADO_REVISION 0
#define DESPERADO_VERSION_STRING "1.0"
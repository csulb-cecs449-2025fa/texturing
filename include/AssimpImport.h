#pragma once
#include "Mesh3D.h"
#include "Object3D.h"
#include <assimp/scene.h>

Object3D assimpLoad(const std::string& path, bool flipTextureCoords);

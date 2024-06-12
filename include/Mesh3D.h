#pragma once
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <vector>
#include "StbImage.h"

struct Vertex3D {
	float x;
	float y;
	float z;

	float u;
	float v;
};

class Mesh3D {
private:
	uint32_t m_vao;
	uint32_t m_texture;
	size_t m_vertexCount;
	size_t m_faceCount;

public:
	Mesh3D() = delete;


	/**
	 * @brief Construcst a Mesh3D using existing vectors of vertices and faces.
	*/
	Mesh3D(const std::vector<Vertex3D>& vertices, const std::vector<uint32_t>& faces,
		const StbImage& texture);

	/**
	 * @brief Constructs a 1x1 square centered at the origin in world space.
	*/
	static Mesh3D square(const StbImage& texture);
	/**
	 * @brief Constructs a 1x1x1 cube centered at the origin in world space.
	*/
	static Mesh3D cube(const StbImage& texture);
	/**
	 * @brief Constructs the upper-left half of the 1x1 square centered at the origin.
	*/
	static Mesh3D triangle(const StbImage& texture);

	/**
	 * @brief Renders the mesh to the given context.
	 */
	void render();

};

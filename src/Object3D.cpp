#include "Object3D.h"
#include "ShaderProgram.h"

glm::mat4 Object3D::buildModelMatrix() const {
	auto m = glm::translate(glm::mat4(1), m_position);
	m = glm::scale(m, m_scale);
	m = glm::rotate(m, m_orientation[2], glm::vec3(0, 0, 1));
	m = glm::rotate(m, m_orientation[0], glm::vec3(1, 0, 0));
	m = glm::rotate(m, m_orientation[1], glm::vec3(0, 1, 0));
	return m;
}

Object3D::Object3D(std::shared_ptr<Mesh3D>&& mesh) : m_mesh(mesh), m_position(), m_orientation(), m_scale(1.0) {
}

const glm::vec3& Object3D::getPosition() const {
	return m_position;
}

const glm::vec3& Object3D::getOrientation() const {
	return m_orientation;
}

const glm::vec3& Object3D::getScale() const {
	return m_scale;
}

void Object3D::setPosition(const glm::vec3& position) {
	m_position = position;
}

void Object3D::setOrientation(const glm::vec3& orientation) {
	m_orientation = orientation;
}

void Object3D::setScale(const glm::vec3& scale) {
	m_scale = scale;
}

void Object3D::move(const glm::vec3& offset) {
	m_position = m_position + offset;
}

void Object3D::rotate(const glm::vec3& rotation) {
	m_orientation = m_orientation + rotation;
}

void Object3D::grow(const glm::vec3& growth) {
	m_scale = m_scale * growth;
}

void Object3D::render(ShaderProgram& shaderProgram) const {
	auto modelMatrix = buildModelMatrix();
	
	shaderProgram.setUniform("model", modelMatrix);
	m_mesh->render();
}

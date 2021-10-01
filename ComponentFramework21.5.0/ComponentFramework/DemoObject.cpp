#include "DemoObject.h"

#include "MMath.h"

DemoObject::DemoObject(Mesh *mesh_, Shader *shader_, Texture *texture_): 
	parent(nullptr), mesh(mesh_), shader(shader_), texture(texture_) {	
}

DemoObject::DemoObject(DemoObject* parent_, Mesh* mesh_, Shader* shader_, Texture* texture_):
	parent(parent_), mesh(mesh_), shader(shader_), texture(texture_) {
}

DemoObject::~DemoObject() {}

bool DemoObject::OnCreate() { return true;  } /// Just a stub
void DemoObject::OnDestroy() {}				  /// Just a stub
void DemoObject::Update(float deltaTime_) {} /// Just a stub

void DemoObject::Render() const {
	Matrix4 parentModelMatrix;
	if (parent != nullptr) {
		parentModelMatrix = parent->getModelMatrix();
	}
	
	Matrix3 normalMatrix = MMath::transpose(MMath::inverse(parentModelMatrix * modelMatrix));

	glUniformMatrix4fv(shader->getUniformID("modelMatrix"), 1, GL_FALSE, parentModelMatrix * modelMatrix);
	glUniformMatrix3fv(shader->getUniformID("normalMatrix"), 1, GL_FALSE, normalMatrix);
	if (texture) {
		glBindTexture(GL_TEXTURE_2D, texture->getTextureID());
	}
	mesh->Render();

	/// Unbind the texture
	if (texture) {
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

void DemoObject::HandleEvents(const SDL_Event &event) {} /// Just a stub
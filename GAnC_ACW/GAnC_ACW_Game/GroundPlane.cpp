#include "GroundPlane.h"

GroundPlane::GroundPlane(int id, Vector3 scale)
	: Entity(id, "GroundPlane")
{
	TransformComponent* tc = new TransformComponent(this);
	tc->position = Vector3(0.0f, 0.0f, 0.0f);
	tc->scale = scale;

	RenderComponent* rc = new RenderComponent(this);
	rc->SetMesh("mesh_plane.txt");
}

GroundPlane::~GroundPlane()
{

}
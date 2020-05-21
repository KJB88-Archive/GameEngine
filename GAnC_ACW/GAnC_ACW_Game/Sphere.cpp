#include "Sphere.h"

Sphere::Sphere(int id, Vector3 pos)
	: Entity(id, "Sphere")
{
	TransformComponent* tc = new TransformComponent(this);
	tc->position = pos;

	PhysicsComponent* pc = new PhysicsComponent(this);

	ColliderSphereComponent* csc = new ColliderSphereComponent(this);
	csc->radius = 1.0f;

	RenderComponent* rc = new RenderComponent(this);
	rc->SetMesh("mesh_sphere.txt");
}

Sphere::~Sphere()
{

}

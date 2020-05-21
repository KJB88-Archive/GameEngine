#include "TestObject.h"

TestObject::TestObject(int id)
	: Entity(id, "TestEntity")
{
	TransformComponent* tc = new TransformComponent(this);
	tc->position = Vector3(0.0f, 0.0f, 1.0f);

	RenderComponent* rc = new RenderComponent(this);
	rc->SetMesh("mesh_square.txt");

}

TestObject::~TestObject()
{

}
